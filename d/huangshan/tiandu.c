//Cracked by Roath
// 天都峰顶
// Dong  01/20/97.
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{   set("short", "天都峰顶");
    set("long", @LONG
天都峰传说是天上的都会，它是黄山三大主峰中最险峻的奇峰。
峰顶有一石刻“登峰造极”。从峰顶极目远眺，云山相接，江河一线；
俯瞰群山，千峰秀色尽收眼底。
LONG);

    set("exits", ([ /* sizeof() == 1 */
	"down" : __DIR__"jiyunbei",
		 ])
	 );
    setup();
    replace_program(ROOM);
}
//Should add an action in it for this.  or maybe just timer action.
//正欣赏得入神，忽然烟云从谷中升起，远近山川夷为一片银海，远方海
//天相接，溶为一体，只有几座比较高耸的山尖露出海面，好似大海中的
//孤岛，你就站在其中的一座孤岛上。渐渐大海涨潮，云水四漫，不多久
//就漫过你的脚面，在你腿缝中流淌，甚至能听到沙沙的流动声。再过一
//会连你也淹没了，眼前一片迷迷茫茫。这时候你千万别走动，耐心等一
//会，马上就会云开雾散，阳光普照。
