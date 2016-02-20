//Cracked by Roath
// Room: /d/xiangyang/huiguan.c

inherit ROOM;

void create()
{
	set("short", "山陕会馆");
	set("long", @LONG
正前方有座悬鉴楼，其两侧为钟鼓楼。楼前有琉璃照壁，用釉瓷雕花均大
方砖砌成，图案精巧，金碧辉煌。会馆中心是大拜殿，幽敞深邃；檐下木雕《
西游记》、《封神演义》等神话传说。殿前石栏又刻“渔樵耕读”，左壁刻“
十八学士朝瀛洲”等。殿前立石牌坊一座，上雕“八爱图”、“金龙缠玉柱”
等。牌坊下铺“九龙口”，气势雄伟，工艺精湛，布局严谨。
LONG
	);
	set("outdoors", "xiangyang");
	set("no_clean_up", 0);
        set("coordinates", ([ "x" : 3, "y" : 10 ]) );
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"shanlu2",
]));

	setup();
	replace_program(ROOM);
}
