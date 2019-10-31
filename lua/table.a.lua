mod = {dirty = false, data = {}}
print(#mod)

table.insert(mod, 12)
print(#mod)
for k, v in ipairs(mod) do
    print(k)
end
