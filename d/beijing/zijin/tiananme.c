//Cracked by Roath
inherit ROOM;

void create()
{
	set("short", "天安门 ");
	set("long",  @LONG
雄威壮观的天安门城楼，代表着王朝的强大，疆土的辽阔。各藩
国，各驸属国的使者从四面八方向天安门奔来，带来各国的物产。门
前两个高大雄武的石狮向人们展示着帝国的威姿。
LONG
	);

	set("exits",([
		"north" : __DIR__"duanmen",
	]));

	set("outdoors","beijing");
	setup();
	replace_program(ROOM);
}