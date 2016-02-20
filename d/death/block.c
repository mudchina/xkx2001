//Cracked by Roath
inherit ROOM;

void create()
{
	set("short","死刑室");
	set("long","在这里只有死路一条...\n");
	set("valid_startroom",1);
	set("cost", 0);
	setup();
}

void init()
{
	object ob = this_player();

	if (!wizardp(ob)) {
		add_action("block_cmd","",1);
		ob->set("startroom", "/d/death/death");
		ob->set("block", 1);
	}
}

int block_cmd()
{
	string cmd;
	cmd = query_verb();
	if ( cmd == "quit" || cmd == "suicide" || cmd == "goto")
		return 0;
	return 1;
}
