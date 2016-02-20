//Cracked by Roath
#include <room.h>
inherit ROOM;

void create()
{
        set("short", "磁窑口");
        set("long", 
"磁窑口为恒山东主峰和西侧翠屏峰之间的连接要道，自谷中
望去，两峰对峙，断崖绿带，层次分明，蔚为壮观。磁窑口位于
峡谷之中，最窄处不足三丈，青天一线，形成绝塞天险，自古为
兵家必争要道。\n");
        
set("exits", ([
                "westup"  : __DIR__"wusean",
                "eastup"   : __DIR__"xuankongsi",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "hengshan");
        set("cost", 1);
        setup();
        replace_program(ROOM);
}

