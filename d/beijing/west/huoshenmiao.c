//Cracked by Roath
// Room: /d/beijing/west/huoshenmiao.c

inherit ROOM;

void create()
{
	set("short", "火神庙");
	set("long", @LONG
这是一座略显破败的火神庙，红袍红脸红胡子的火神爷坐在庙正
中。从庙门望出去可以看到鼓楼，大概当初修建鼓楼时怕遭火灾，所
以修了这个火神庙，求火神爷保佑。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
	"west" : __DIR__"jingshanjie",
	]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
