--OOlua file_generator
create_package("file_generator","../","ConsoleApp")

configuration {}

files 
{ 
    	"*.h",
    	"*.cpp"
}
includedirs 
{
	"include/lua",
	"/usr/local/include",
	"/usr/include",
} 

