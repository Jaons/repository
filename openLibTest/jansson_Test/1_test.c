#include <stdio.h>
#include <string.h>
#include <jansson.h>

int main(int argc, char **argv)
{
    int                     ret = 0;
    json_int_t              j_number;
    json_t                  *json;
    json_error_t            j_error;

    json = json_load_file("/home/zhouxw/repository/openLibTest/jansson_Test/json_file/baidu.search.html.json", 0, &j_error);
    //json = json_load_file("/home/zhouxw/repository/openLibTest/jansson_Test/json_file/baidu.search.htmlss.json", 0, &j_error);
    
    if (!json) {
        printf("error occur in line:%d column:%d: %d, %s, %s\n", j_error.line, j_error.column, j_error.position, j_error.source, j_error.text);
        return 0;
    } else {
        printf("load json_file done\n");

        // dump into other file
        json_dump_file(json, "./test.json", JSON_COMPACT|JSON_INDENT(4));
        return 0;
    }
    
    
}
