//Cracked by Roath
// danyaofang.c 丹药房
// xQin 11/00


inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", "丹药房" );
	set("long", @LONG
这里是武当派的丹药房，只见室内一排排的架子井然有序，架子(shelf)
上排列着一个个小白瓷瓶子。所有药材和丹药都送到这里腊封密存，屋内飘
逸着一股淡淡的药香。
LONG
	);
	set("no_fight", 1);
	set("exits", ([
		"south" : __DIR__"xilang1",
	]));
	
	set("objects", ([
	"/kungfu/class/wudang/yudaiyan.c" : 1,
	
	]));
	
	set("item_desc",([
	"shelf" : "
只见架子上整齐的摆着几个"HIW"白瓷瓶"NOR"，瓶子上都分别贴这不同的条子(tiaozi)。\n",
	"tiaozi" : "
仔细一看原来条子上写的都是瓶内的药名：

※※※※	※※※※	※※※※	※※※※
※ 天 ※        ※ 三 ※	※ 天 ※	※ 白 ※
※ 心 ※	※ 黄 ※	※ 王 ※	※ 虎 ※
※ 解 ※	※ 宝 ※	※ 护 ※	※ 夺 ※
※ 毒 ※	※ 腊 ※	※ 心 ※	※ 命 ※
※ 丹 ※	※ 丸 ※	※ 丹 ※	※ 丸 ※
※※※※	※※※※	※※※※	※※※※ \n\n"
	
	]));
	
	setup();
	replace_program(ROOM);
}

