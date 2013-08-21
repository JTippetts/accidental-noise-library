package.path=package.path..";.\\testgame\\?.lua;.\\testgame\\?.lc"

require 'linkedlist'
require 'tokenize'

function priority(token)
	if token=="*" or token=="/" then return 2 end
	if token=="+" or token=="-" then return 1 end
	return 0
end
 
 
function InfixToPrefix(s)
	local tokens=s:tokenize()
	local stack=LinkedList()
	local pf=""
	local i
 
	for i=1,#tokens,1 do
		local token=tokens[i]
		--print("token: "..token)
 
		if token=="(" then
			stack:push_front(token)
		elseif token==")" then
			while stack:getFront() ~= "(" do
				pf=stack:popFront().." "..pf
			end
			stack:popFront()
		elseif token=="+" or token=="-" or token=="*" or token=="/" then
			while priority(stack:getFront()) > priority(token) do
				pf=stack:popFront().." "..pf
			end
			stack:push_front(token)
		else
			pf=token.." "..pf
		end
	end
	while stack:isEmpty()==false do
		pf=stack:popFront().." "..pf
	end
	print(pf)
	return pf
end

function GetPrefixNode(tokenstack)
	local token=tokenstack:popFront()
	
	local node={}
	
	if token=="*" or token=="+" or token=="-" then
		
		node.value=token
		node.type="operator"
		node.right=GetPrefixNode(tokenstack)
		node.left=GetPrefixNode(tokenstack)
	else
		if token=="x" or token=="y" or token=="z" or token=="w" or token=="u" or token=="v" then
			
			node.type="operand"
			node.operandtype="unknown"
			node.value=token
		else
			
			node.type="operand"
			node.operandtype="constant"
			node.value=token
		end
	end
	
	return node
end

function ParsePrefix(pf)
	local tokens=pf:tokenize()
	local tokenstack=LinkedList()
	local i
	for i=1,#tokens,1 do
		tokenstack:push_back(tokens[i])
	end
	
	local tree=GetPrefixNode(tokenstack)
	
	return tree
	
end

function TraverseTree(tree)
	if(tree.left) then TraverseTree(tree.left) end
	print(tree.value)
	if(tree.right) then TraverseTree(tree.right) end
end

function TraverseTreePrefix(tree)
	local s=tree.value.." "
	if tree.right then s=s..TraverseTreePrefix(tree.right,s) end
	if tree.left then s=s..TraverseTreePrefix(tree.left,s) end
	return s
end

function BuildTermList(tree,buckets,parentsign)
	if tree.type=="operator" and tree.value=="*" then
		if buckets[tree.left.value]==nil then buckets[tree.left.value]={} end
		table.insert(buckets[tree.left.value], parentsign..tree.right.value)
	end
	
	if tree.type=="operator" and (tree.value=="-" or tree.value=="+") then
		if tree.left.type=="operator" then
			BuildTermList(tree.left, buckets, "+")
		else
			if buckets["nocoeff"]==nil then buckets["nocoeff"]={} end
			table.insert(buckets["nocoeff"], "+"..tree.left.value)
		end
		
		if tree.right.type=="operator" then
			BuildTermList(tree.right, buckets, tree.value)
		else
			if buckets["nocoeff"]==nil then buckets["nocoeff"]={} end
			table.insert(buckets["nocoeff"], "+"..tree.left.value)
		end
	end
end

function ExpandNode(node)
	if node.type=="operator" then
		node.left=ExpandNode(node.left)
		node.right=ExpandNode(node.right)
 
		-- Now, apply unknown multiplication simplification rule
		if node.value=="*" then
			if node.left.type=="operand" and node.left.operandtype=="unknown" and node.right.type=="operand" and node.right.operandtype=="unknown" then
				-- This simplifies down to a node
				local newnode={}
				newnode.type="operand"
				newnode.operandtype="unknown"
				newnode.value=node.left.value..node.right.value
				return newnode
			elseif node.left.type=="operand" and node.left.operandtype=="unknown" and node.right.type=="operator" and node.right.value=="*" and node.right.left.type=="operand" and node.right.left.operandtype=="unknown" then
				local newnode={}
				newnode.type="operator"
				newnode.value="*"
				newnode.left={}
				newnode.left.type="operand"
				newnode.left.operandtype="unknown"
				newnode.left.value=node.left.value..node.right.left.value
				newnode.right=node.right.right
				newnode.left=ExpandNode(newnode.left)
				newnode.right=ExpandNode(newnode.right)
				return newnode
			elseif node.left.type==operand and node.left.operandtype=="coeff" and node.right.type=="operand" and node.right.operandtype=="unknown" then
				-- Switch this one around
				local newnode={}
				newnode.type="operator"
				newnode.value=node.value
				newnode.left=node.right
				newnode.right=node.left
				return newnode
			else
				if node.left.type=="operator" and node.right.type=="operand" then print("swap") node.left,node.right=node.right,node.left end -- Swap
					if node.left.type=="operand" and node.right.type=="operator" and (node.right.value=="+" or node.right.value=="-") then
					--print("expand")
					-- Expand this one using distributive
					local newnode={}
					newnode.type="operator"
					newnode.value=node.right.value
					newnode.left={}
					newnode.left.type="operator"
					newnode.left.value="*"
					newnode.right={}
					newnode.right.type="operator"
					newnode.right.value="*"
	
					newnode.left.left=node.left
					newnode.left.right=node.right.left
					newnode.right.left=node.left
					newnode.right.right=node.right.right
	
					newnode.left=ExpandNode(newnode.left)
					newnode.right=ExpandNode(newnode.right)
	
					return newnode
				end
			end
		end
	end
	
	return node
end
 
 
-- Function to invert the +/- signs of a tree chain
function InvertSigns(node)
	if node.type=="operator" then
		if node.value=="+" then
			node.value="-" 
		elseif node.value=="-" then 
			node.value="+" 
		end
		if node.value=="+" or node.value=="-" then
			InvertSigns(node.left)
			InvertSigns(node.right)
		end
	end
end
 
-- function to check a node to see if it is a subtraction operation, and if the right child is an addition or subtraction. If so, invert the operation of the right
-- child.
 
function InvertSubtractions(node)
	if node.type=="operator" then
		InvertSubtractions(node.left)
		InvertSubtractions(node.right)
	end
	if node.type=="operator" and node.value=="-" then
		InvertSigns(node.right)
	end
end


function lerp(t,a,b)
	return "( "..a.." + "..t.." * ( "..b.." - "..a.." ) ) "
end
 
function lerp2(s,t,a,b,c,d)
	return lerp(t,lerp(s,a,b),lerp(s,c,d))
end
 
function lerp3(s,t,u,a,b,c,d,e,f,g,h)
	return lerp(u, lerp2(s,t,a,b,c,d), lerp2(s,t,e,f,g,h))
end
 
function lerp4(s,t,u,v,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p)
	return lerp(v, lerp3(s,t,u,a,b,c,d,e,f,g,h), lerp3(s,t,u,i,j,k,l,m,n,o,p))
end
 
function lerp5(s,t,u,v,w,A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z,AA,BB,CC,DD,EE,FF)
	return lerp(w,lerp4(s,t,u,v,A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P), lerp4(s,t,u,v,Q,R,S,T,U,V,W,X,Y,Z,AA,BB,CC,DD,EE,FF))
end
 
function lerp6(s,t,u,v,w,x,A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z,AA,BB,CC,DD,EE,FF,GG,HH,II,JJ,KK,LL,MM,NN,OO,PP,QQ,RR,SS,TT,UU,VV,WW,XX,YY,ZZ,AAA,BBB,CCC,DDD,EEE,FFF,GGG,HHH,III,JJJ,KKK,LLL)
	return lerp(x, lerp5(s,t,u,v,w,A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z,AA,BB,CC,DD,EE,FF), lerp5(s,t,u,v,w,GG,HH,II,JJ,KK,LL,MM,NN,OO,PP,QQ,RR,SS,TT,UU,VV,WW,XX,YY,ZZ,AAA,BBB,CCC,DDD,EEE,FFF,GGG,HHH,III,JJJ,KKK,LLL))
end


function TreeDepth(tree)
	local rdepth,ldepth=0,0
	if tree.left then ldepth=TreeDepth(tree.left) end
	if tree.right then rdepth=TreeDepth(tree.right) end
	
	return math.max(rdepth,ldepth)+1
end

function PrintRows(tree,rows,maxdepth,depth, offset)
	
	if rows[depth]==nil then
		print("Row "..depth.." does not exist.")
		rows[depth]={}
	end
	print("Depth: "..depth.." Offset: "..offset)
	rows[depth][offset]=tree.value
	
	
	
	if tree.left then
		PrintRows(tree.left,rows,maxdepth,depth+1, offset)
	end
	if tree.right then
		PrintRows(tree.right,rows,maxdepth,depth+1, offset+(math.pow(2,(maxdepth-(depth+1)))))
	end
end

function PrintTree(tree, filename)
	local depth=TreeDepth(tree)
	print("Depth: "..depth)
	
	rows={}
	local width=math.pow(2,(depth-1))
	local i=1
	for i=1,depth,1 do
		rows[i]={}
		for j=1,width,1 do
			rows[i][j]=" "
		end
		
	end
	
	PrintRows(tree,rows,depth,1,1)
	
	local j,k,l
	for i,j in pairs(rows) do
		local s=""
		for k,l in pairs(j) do
			s=s..l
		end
		print(s)
	end
	
	if filename then
		out=io.open(filename, "w")
		
		local i,j,k,l
		for i,j in pairs(rows) do
			local s=""
			for k,l in pairs(j) do
				s=s..l
			end
			out:write(s.."\n")
		end
		
		out:close()
	end
end

function GenerateTerms(tree)
	local s=""
	
	if tree.left then s=s..GenerateTerms(tree.left) end
	if tree.value=="+" or tree.value=="-" then
		s=s.."# "
	end
	s=s..tree.value.." "
	if tree.right then s=s..GenerateTerms(tree.right) end
	
	return s
end

function BuildBuckets(terms)
	local t=terms:split("#")
	local buckets={}
	
	local i,term
	for i,term in pairs(t) do
		local tokens=term:tokenize()
		if #tokens==1 then
			if buckets["misc"]==nil then buckets["misc"]={} end
			table.insert(buckets["misc"], tokens[1])
		else
			if buckets[tokens[2]]==nil then
				buckets[tokens[2]]={}
				if tokens[1]=="+" then
					table.insert(buckets[tokens[2]], tokens[4])
				else
					table.insert(buckets[tokens[2]], tokens[1]..tokens[4])
				end
			else
				table.insert(buckets[tokens[2]], tokens[1]..tokens[4])
			end
		end
	end
	return buckets
end

function BGE(dim)
	local expr={}
	local points=math.pow(2,dim)
	local ind=""
	if dim==2 then
		expr=lerp2("x","y","P[0]","P[1]", "P[2]", "P[3]")
		ind="\"x\", \"y\""
	elseif dim==3 then
		expr=lerp3("x","y","z","P[0]","P[1]", "P[2]", "P[3]","P[4]","P[5]","P[6]","P[7]")
		ind="\"x\", \"y\", \"z\""
	elseif dim==4 then
		expr=lerp4("x","y","z","w","P[0]","P[1]", "P[2]", "P[3]","P[4]","P[5]","P[6]","P[7]","P[8]","P[9]","P[10]","P[11]","P[12]","P[13]","P[14]","P[15]")
		ind="\"x\",\"y\",\"z\",\"w\""
	elseif dim==5 then
		expr=lerp5("x","y","z","w","u","P[0]","P[1]", "P[2]", "P[3]","P[4]","P[5]","P[6]","P[7]","P[8]","P[9]","P[10]","P[11]","P[12]","P[13]","P[14]","P[15]","P[16]","P[17]","P[18]","P[19]","P[20]","P[21]","P[22]","P[23]","P[24]","P[25]","P[26]","P[27]","P[28]","P[29]","P[30]","P[31]")
		"\"x\",\"y\",\"z\",\"w\",\"u\""
	elseif dim==6 then
		expr=lerp6("x","y","z","w","u","v","P[0]","P[1]", "P[2]", "P[3]","P[4]","P[5]","P[6]","P[7]","P[8]","P[9]","P[10]","P[11]","P[12]","P[13]","P[14]","P[15]","P[16]","P[17]","P[18]","P[19]","P[20]","P[21]","P[22]","P[23]","P[24]","P[25]","P[26]","P[27]","P[28]","P[29]","P[30]","P[31]","P[32]","P[33]","P[34]","P[35]","P[36]","P[37]","P[38]","P[39]","P[40]","P[41]","P[42]","P[43]","P[44]","P[45]","P[46]","P[47]","P[48]","P[49]","P[50]","P[51]","P[52]","P[53]","P[54]","P[55]","P[56]","P[57]","P[58]","P[59]","P[60]","P[61]","P[62]","P[63]")
		ind="\"x\",\"y\",\"z\",\"w\",\"u\",\"v\""
	else
		return
	end
	
	local prefix=InfixtoPrefix(expr)
	local tree=ParsePrefix(prefix)
	local expand=ExpandNode(tree)
	InvertSubtractions(expand)
	
	local terms=GenerateTerms(expand)
	local buckets=BuildBuckets(terms)
	
	
end

function BuildGeneratorExpression(buckets)
	local i,j
	local expr=""
	
	for i,j in pairs(buckets) do
		if i~="misc" then
			expr=expr..AddMultSignToUnknown(i).."*k"..i.."+ "
		end
	end
	
	expr=expr.."kmisc"
	return expr
end

function BuildConstantList(buckets)
	local i,j
	local ks={}
	
	for i,j in pairs(buckets) do
		local k,l
		local s="ANLFloatType k"..i.."="
		for k,l in pairs(j) do
			s=s..l
		end
		s=s..";"
		
		table.insert(ks, s)
	end
	
	return ks
end

function UnknownHasComponent(unk,which)
	local s,e=unk:find(which)
	if s then return true else return false end
end

function UnknownStripComponent(unk,which)
	return unk:gsub(which,"")
end

function BuildDerivExpression(buckets, which)
	local i,j
	local expr="d"..which.." * ("
	for i,j in pairs(buckets) do
		if i~="misc" then
			if UnknownHasComponent(i,which) then
				local t=AddMultSignToUnknown(UnknownStripComponent(i,which))
				if t~="" then
					expr=expr..AddMultSignToUnknown(UnknownStripComponent(i,which)).."*k"..i.."+ "
				else
					expr=expr.."k"..i.."+ "
				end
			end
		end
	end
	expr=expr..");"
	return expr
end

function AddMultSignToUnknown(unk)
	-- Split an unknown string (ie, something like "xyz" and
	-- insert * signs to build a multiplication operation
	
	if unk:len()==1 then return unk end
	if unk=="" then return "" end
	
	local s={}
	local prf=unk:sub(1,1)
	unk=unk:sub(2,-1)
	while prf~="" do
		table.insert(s,prf)
		prf=unk:sub(1,1)
		unk=unk:sub(2,-1)
	end
	
	local str=""
	local i
	for i=1,#s-1,1 do
		str=str..s[i].."*"
	end
	str=str..s[#s]
	
	return str
end
expr=lerp6("x","y","z","w","u","v","P[0]","P[1]", "P[2]", "P[3]","P[4]","P[5]","P[6]","P[7]","P[8]","P[9]","P[10]","P[11]","P[12]","P[13]","P[14]","P[15]","P[16]","P[17]","P[18]","P[19]","P[20]","P[21]","P[22]","P[23]","P[24]","P[25]","P[26]","P[27]","P[28]","P[29]","P[30]","P[31]","P[32]","P[33]","P[34]","P[35]","P[36]","P[37]","P[38]","P[39]","P[40]","P[41]","P[42]","P[43]","P[44]","P[45]","P[46]","P[47]","P[48]","P[49]","P[50]","P[51]","P[52]","P[53]","P[54]","P[55]","P[56]","P[57]","P[58]","P[59]","P[60]","P[61]","P[62]","P[63]")
--expr=lerp4("x","y","z","w","P[0]","P[1]", "P[2]", "P[3]","P[4]","P[5]","P[6]","P[7]","P[8]","P[9]","P[10]","P[11]","P[12]","P[13]","P[14]","P[15]")
--expr=lerp3("x","y","z","P[0]","P[1]", "P[2]", "P[3]","P[4]","P[5]","P[6]","P[7]")
--expr=lerp2("x", "y", "a", "b", "c", "d")
--expr=lerp("x", "a", "b")

prefix=InfixToPrefix(expr)
tree=ParsePrefix(prefix)
--PrintTree(tree, "basetree.txt")

expand=ExpandNode(tree)
--PrintTree(expand, "expandtree.txt")

InvertSubtractions(expand)
--PrintTree(expand, "invertedtree.txt")

terms=GenerateTerms(expand)

--print("Terms: "..terms)

buckets=BuildBuckets(terms)

out=io.open("out.txt", "w")

ks=BuildConstantList(buckets)

for i,j in pairs(ks) do
	print(j)
	out:write(j.."\n")
end

gen=BuildGeneratorExpression(buckets)
print(gen)

out:write(gen.."\n\n")

dx=BuildDerivExpression(buckets, "x")
print(dx)
out:write(dx.."\n\n")

dx=BuildDerivExpression(buckets, "y")
print(dx)
out:write(dx.."\n\n")

dx=BuildDerivExpression(buckets, "z")
print(dx)
out:write(dx.."\n\n")

dx=BuildDerivExpression(buckets, "w")
print(dx)
out:write(dx.."\n\n")

dx=BuildDerivExpression(buckets, "u")
print(dx)
out:write(dx.."\n\n")

dx=BuildDerivExpression(buckets, "v")
print(dx)
out:write(dx.."\n\n")

out:close()