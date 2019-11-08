function init(mod)
    for _, v in pairs(mod) do
        print(v)
    end
end

init{
    first = 1,
    second = 2,
}
