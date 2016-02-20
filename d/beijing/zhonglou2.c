//Cracked by Roath
// Room: /d/beijing/zhonglou2.c


inherit ROOM;
#include "/d/beijing/beijing_defs.h"

int do_qiao(string arg);

void create()
{
	set("short", "钟楼二层");
	set("long", @LONG
这里是钟楼上层的小屋子。青铜铸造的铜钟 (zhong) 已经发绿，
旁边的撞槌看起来也历经沧桑。清晨的时候这里的士兵会敲钟以示更
次，钟声全城都听得见。屋子角上有个士兵在打盹儿。
LONG
	);
	set("exits", ([ 
	"down" : __DIR__"zhonglou",
	]));
	
 	set("item_desc", ([
	"zhong" : "一只巨大的青铜钟。\n"
		  "你忍不住想敲(qiao)一下，可是又怕惊醒旁边的士兵。\n",
	]));
	set("no_clean_up", 0);
	set("outdoors", "beijing");
	set("cost", 2);

	setup();
	remove_call_out("auto_qiao");
	call_out("auto_qiao", 120);
}

void init()
{
    add_action("do_qiao", "qiao");
}

#define LOUD_SOUND "钟楼的大钟发出一声声巨响：“当，当，当。。。”，震得你耳朵都要聋了。\n"
#define NORMAL_SOUND "钟楼的大钟响了起来：“当，当，当。。。”。\n"
#define WEAK_SOUND "一阵钟声从远处传来：“当，当，当。。。”。\n"
#define FADE_SOUND "远处传来依稀可辨的钟声：“当，当，当，。。。”。\n"

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

void make_zhong_sound()
{
    int     i, j;
    object  trav;

    trav = new(TRAVERSER);
    if (! objectp(trav)) return;

    trav->traverse(base_name(this_object()), (:visit_room:), 0);
}

int do_qiao(string arg)
{
    object player = this_player();
    object bing;

    if (! arg || arg != "zhong") return notify_fail("你要敲什么？\n");
    if (present("bing", environment(player)) )
	return notify_fail("你想去敲钟，但是士兵拦住了你。\n");
    
    message_vision("$N趁着士兵在打盹，猛的敲了一下大钟。\n",
	player);
    make_zhong_sound();
    bing = new("/d/beijing/npc/bj_bing");
    bing->move(environment(player));
    message_vision("正在打盹的士兵被吓得跳了起来。\n", player);
    player->apply_condition("bjkiller", 100);
    return 1;
}

int auto_qiao()
{
    if (HELPER->shichen() == 8) make_zhong_sound();
    remove_call_out("auto_qiao");
    call_out("auto_qiao", 120);
    return 1;
}
