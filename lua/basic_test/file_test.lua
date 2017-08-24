--file = io.open("test.txt","a");
--io.output(file);
--io.write("hello lua");
--io.close();
--
file = io.input("test.txt")
io.input(file)
repeat
    line = io.read()
    if nil == line then
        break
    end
    print(line)
until (false)

