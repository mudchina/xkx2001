//Cracked by Roath
// 温泉
// Dong  01/20/97.
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{   set("short", "汤池");
    set("long", @LONG
被誉为黄山“四绝”之一的温泉(又称汤池)，出自紫云峰峦的石
壁之下，同迤逦十里的桃花峰隔溪相望。温泉泉边石壁题刻着“天下
名泉”四个大字。此泉水清如碧，可饮可浴。
LONG);

    set("exits", ([ /* sizeof() == 3 */
	"west" : __DIR__"renzipu",
	"north" : __DIR__"ciguang",
	"northeast" : __DIR__"baizpu",
		 ])
	 );
    setup();
    replace_program(ROOM);
}
// 从泉里爬出来，满身的盐腥汗味一洗而光，多日的疲劳困倦
// 顿时消失。你感到身轻如燕，不禁为诗句“五岳若与黄
// 山并，犹欠灵砂一道泉”拍手叫绝。
