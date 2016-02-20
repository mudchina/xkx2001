//Cracked by Roath
// Room: /d/beijing/west/wumiao.c

inherit ROOM;

void create()
{
	set("short", "武庙");
	set("long", @LONG
这里是岳王庙的正殿，内有岳忠武王像，塑像全身披挂，面不朝
南而朝东。上方悬挂岳飞手书“还我河山”的横匾。殿两侧壁上嵌着
“精忠报国”四个大字。庙前空地有秦桧夫妇捆绑的跪像。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
	"west" : __DIR__"deshengjie",
	]));
	
	set("no_clean_up", 0);
	set("no_fight", 1);

	setup();
	replace_program(ROOM);
}
