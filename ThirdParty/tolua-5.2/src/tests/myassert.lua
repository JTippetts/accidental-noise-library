function assert (status,msg) 
   if not status then 
      print("ERROR: " .. (msg or "assertion failed")) error() 
   end 
end

