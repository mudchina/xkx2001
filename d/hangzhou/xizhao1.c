//Cracked by Roath
// 夕照山
// Dong  11/03/1996.
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{   set("short", RED"夕照山"NOR);
    set("long", @LONG
夕照山上遍植栖树和红枫。每逢深秋，层林尽染，分外壮观。山
顶有一座塔，雷峰塔。神话“白蛇传”中的白娘娘就是被法海禁锢在
这座塔里。每当夕阳西下，彩云缭绕，塔影幢幢，这就是西湖十景之一
的“雷峰夕照”。
LONG	);

    set("exits", ([ /* sizeof() == 1 */ 
                   "southdown" : __DIR__"road72", 
                 ])
       );
	set("cost", 3);
        set("outdoors", "hangzhou");
    setup();
    replace_program(ROOM);
}
