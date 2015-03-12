local a = A:new()
local b = a:GetB()
local t = {}
for i = 1, 100 do
  t[i] = a:GetB()
  local a, b, c = a:bounce(i,i)
  assert(a==i and b==i and c==i)
end

t = nil
b = nil
collectgarbage("collect")
assert(B.n == 0)
print("VarArg OK")
