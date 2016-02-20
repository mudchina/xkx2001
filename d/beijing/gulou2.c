//Cracked by Roath
// Room: /d/beijing/gulou2.c


inherit ROOM;
#include "/d/beijing/beijing_defs.h"
#include "/d/beijing/bj_rooms.h"

int do_da(string arg);

void create()
{
	set("short", "鼓楼二层");
	set("long", @LONG
这里是鼓楼二楼的小屋子。屋子中间是一面两人怀抱不过来的
大鼓(gu)。傍晚的时候这里的士兵会打鼓以示更次，鼓声全城都听
得见。屋子角上有个士兵在打盹儿。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
	"down" : __DIR__"gulou",
	]));
	
 	set("item_desc", ([
	"gu" : "一面牛皮鼓。旁边的鼓槌已经发白，可见已经有年月了。\n"
		"你见了这大鼓忍不住想打(da)一下，可是又怕惊醒旁边的士兵。\n",
	]));
	set("no_clean_up", 0);
	set("outdoors", "beijing");
	set("cost", 2);

	setup();
	remove_call_out("auto_dagu");
	call_out("auto_dagu", 180);
}

void init()
{
    add_action("do_da", "da");
}

#define LOUD_SOUND "鼓楼的大鼓发出一声声巨响：“咚，咚，咚。。。”，震得你耳朵都要聋了。\n"
#define NORMAL_SOUND "鼓楼的大鼓响了起来：“咚，咚，咚。。。”。\n"
#define WEAK_SOUND "一阵鼓声从远处传来：“咚，咚，咚。。。”。\n"
#define FADE_SOUND "远处传来依稀可辨的鼓声：“咚，咚，咚，。。。”。\n"
int visit_room(string room_path, mapping info, mapping mapdb_info, mixed args)
{
  object room;
 
  if (strsrch(room_path, "/d/beijing/") != 0) return 1;  // prune
  room = find_object(room_path);
  if (!objectp(room)) return 0;
  if (info["dist"] < 2) {
    message("info", LOUD_SOUND, room, 0);
  }else if (info["dist"] < 8) {
    message("info", NORMAL_SOUND, room, 0);
  }else if (info["dist"] < 12) {
    message("info", WEAK_SOUND, room, 0);
  }else {
    message("info", FADE_SOUND, room, 0);
  }
  return 0;
}
 
void make_gu_sound()
{
    object  trav;
 
    trav = new(TRAVERSER);
    if (! objectp(trav)) return;
 
    trav->traverse(base_name(this_object()), (:visit_room:), 0);
}

int do_da(string arg)
{
    object player = this_player();
    object bing;

    if (! arg || arg != "gu") return notify_fail("你要打什么？\n");
    if (present("bing", environment(player)) )
	return notify_fail("你想去打鼓，但是士兵拦住了你。\n");
    
    message_vision("$N趁着鼓楼士兵在打盹，拿起鼓槌猛的敲了一下大鼓。\n",
	player);
    make_gu_sound();
    bing = new("/d/beijing/npc/bj_bing");
    bing->move(environment(player));
    message_vision("正在打盹的士兵被吓得跳了起来。\n", player);
    player->apply_condition("bjkiller", 100);
    return 1;
}

int auto_dagu()
{
    if (HELPER->shichen() == 19) make_gu_sound();
    remove_call_out("auto_dagu");
    call_out("auto_dagu", 100);
    return 1;
}
