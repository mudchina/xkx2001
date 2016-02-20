//Cracked by Roath
// Room: /city/minwu1.c
// YZC 1996/11/13 

#include <ansi.h>
inherit ROOM;

int do_move(string arg);
int do_look(string arg);

#define SKILL_DB "/clone/obj/skill_db"

void create()
{
	set("short", "民屋");
	set("long",
"这是一个典型的普通老百姓住屋。和别的民屋一样，不大且又破旧的屋子里
只摆放着一张旧桌子和几张老床，几个人正躺在床上睡觉，鼾声如雷，想必这些
壮汉们是累倒了。你发觉右边小床上躺着一个好像还没满月的婴儿正笑眯眯地看
着你，许久也不哭。你像一个小偷似的在房间里走来走去，发现西墙脚放着一个
大"+YEL"米缸"NOR+"(gang)。\n"
	);

	set("exits", ([
		"south" : __DIR__"xiangnanjie",
	]));

	set("objects", ([
		__DIR__"npc/man" : 2,
	]));

	set("cost", 0);
	setup();
}

int init()
{
    add_action("do_move", "move");
    add_action("do_look", "look");
}

void print_enter(mapping enter)
{
	string *names;
	int i, n;

 	n=0;
	if (mapp(enter)) {
   	    names = keys(enter);
	    for (i=0; i<sizeof(names); i++) {
		printf("    %s 进来过 %d 次．\n", names[i], enter[names[i]]);
		n++;
	    }
	}
	if (n == 0) {
	    printf("没人进来过．\n");
	}
}

int do_look(string arg)
{
    object player = this_player();
    object db;
    mapping enter;

    if (arg != "gang") {
        return notify_fail("你要看什么？");
    }
    if (!wizardp(player) && !player->query("futou_bang")) {
        message_vision("$N对着米缸看了半天，发现米缸里有不少米虫．\n",
	    player);
    }else{
        message_vision("$N仔细察看米缸，似乎在研究上面的指纹．．．\n",
	    player);
	db = find_object(SKILL_DB);
        if (!objectp(db)) db = new(SKILL_DB);
        if (!objectp(db)) {
	    message_vision("$N, 请告诉巫师，skill_db 不能被 clone．", player);
	    return 1;
 	}
   	enter = db->query("futou/enter");
        printf("你发现：\n");
	print_enter(enter);
	if (!wizardp(player)) {
	  message_vision("$N仔细地擦了擦米缸的边缘．\n", player);
	  db->delete("futou/enter");
	}
	db->save();

	if (wizardp(player)) {
	    printf("从古到今，进过密室的有：\n");
	    print_enter(db->query("futou/enter_all"));
	}
    }
    return 1;
}

mapping add_enter(mapping enter, object player)
{
  string id = player->query("id");
  int n;

  if (mapp(enter)) {
    n = enter[id];
    enter[id] = n+1;
    return enter;
  }else{
    return ([id:1]);
  }
}

int do_move(string arg)
{
    object player = this_player();
    object db;
    mapping enter;

    if (arg != "gang") {
        return notify_fail("你要挪什么？");
    }
    if (player->query("combat_exp") < 10000 ||  player->query("max_neili") < 1000) {
      message_vision("$N使足了劲去推米缸，可是米缸似乎长在地上一般，纹丝不动．\n",
		     player);
    }else{
      message_vision("$N挪开米缸，地上忽然显露出一个洞口．$N从洞口钻了进去．\n",
		     player);
      player->move("/d/city/ft_room1");

      if (!player->query("futou_bang")) {
	message_vision("$N胆战心惊，不小心踢倒了地上的一个木桩．\n", 
		       player);
      }
      db = find_object(SKILL_DB);
      if (!objectp(db)) db = new(SKILL_DB);
      if (!objectp(db)) {
	message_vision("$N, 请告诉巫师，skill_db 不能被 clone．", player);
      }else{
	enter = db->query("futou/enter");
	enter = add_enter(enter, player);
	db->set("futou/enter", enter);

	enter = db->query("futou/enter_all");
	enter = add_enter(enter, player);
	db->set("futou/enter_all", enter);

	db->save();
      }
      message_vision("$N从洞口钻了进来．\n", player);
    }
    return 1;
}
