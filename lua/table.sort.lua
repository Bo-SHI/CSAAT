local cache = {}
--table.insert(cache, {rid = 1, value = 10, time = 100})
--table.insert(cache, {rid = 2, value = 15, time = 100})
--table.insert(cache, {rid = 3, value = 10, time = 50})

function print_t(t)
    table.sort(cache, function(a, b)
        return a.value > b.value or a.value == b.value and a.time < b.time
    end)
    for k, v in ipairs(t) do
        print(k)
        print(v.rid)
        print(v.value)
        print(v.time)
    end
end

print_t(cache)
