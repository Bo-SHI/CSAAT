active = {}
active[1] = "hello"
active[2] = "world"

for k, v in pairs(active) do
    active[k] = nil
end

for k, v in pairs(active) do
    print(k)
    print(v)
end

local v = nil or 1
print(v)
