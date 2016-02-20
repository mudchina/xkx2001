//Cracked by Roath
// Room: tianchi.c

inherit ROOM;

#include "/d/changbai/caishen.h";

void create()
{
	set("short", "天池");
	set("long", @LONG
这里就是长白的圣湖——天池。它犹如初露水面的莲叶，呈椭圆形，南
窄北宽。周围群峰环列，宛如皑皑雪峰怀抱中的一面翡翠碧玉镜。参客中传
说这里乃是圣地，时而天气晴朗，风和日丽，景色异常秀丽。时而狂风呼啸
，飞沙走石，犹如凶神恶煞一般。因此来到这里的参客，猎户都是必恭必敬
，甚至不敢高声言语。
LONG	);
	set("exits", ([ 
              "westup" : __DIR__"yuzf",
              "eastup" : __DIR__"longmf",
              "northup" : __DIR__"baiyf",
              "southup" : __DIR__"tiyf",
        ]));
	
        set("outdoors", "changbai");

        set("count", random(3)+1);

	setup();
}
