-- table 数组元素的交换

local table = table
local t = {}

table.insert(t, 3)
table.insert(t, 4)
table.insert(t, 8)

print("长度", #t)

local function list(t)
    print("列出数组的元素:")
    for k, v in ipairs(t) do
        print(k)
        print(v)
    end
end

list(t)

print("swap:")
t[1],t[3] = t[3],t[1]
list(t)
