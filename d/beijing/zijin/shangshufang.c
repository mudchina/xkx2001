//Cracked by Roath
// Room: /d/beijing/zijincheng/shangshufang.c

inherit ROOM;

void create()
{
	set("short", "上书房");
	set("long", @LONG
房中一排排都是书架，架子上放满了书，也不知几千几万本。正
中一张极大的紫檀木书桌，桌面金镶玉嵌。桌后有把椅子，上面披了
锦缎，绣了一条金龙，墙上挂了不少名人字画。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"qianqingmen",
  "east" : __DIR__"sikongchu",
]));
	set("no_clean_up", 0);
	set("outdoors", "beijing");
//书桌:这是一张紫檀木书桌，上面摊着一本书，左手放着砚台
//笔筒，右手放着一只香炉。
//香炉:香炉呈长方型，通体以蓝绿釉为底，饰湖景，盖顶饰酚丝锭形纹，中
//绕六角形蜂窝纹，下饰双龙戏珠图。

	setup();
	replace_program(ROOM);
}
