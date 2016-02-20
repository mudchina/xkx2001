//Cracked by Roath
// Room: /d/dali/wangfu13.c

inherit ROOM;

void create()
{
	set("short", "书房");
	set("long", @LONG
房中当地放著一张花梨大理石大案，案上堆著各种名人法帖，并十数方宝砚，
各色笔筒，笔海内插的笔如树林一般；那一边设著斗大的一个汝窑花囊，插著满
满的水晶球的白菊花。西壁当中挂著一米襄阳「烟雨图」。左右挂著一幅对联，
乃是颜鲁公墨迹。其联云：烟霞□骨格，泉石野生涯。案上设著大鼎，左边紫檀
著一个白玉比目鱼磬，傍边挂著小槌。
LONG);
	set("exits", ([
		"southwest" : __DIR__"wangfu9",
		]));
	set("cost", 1);
	set("wangfu", 1);
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
