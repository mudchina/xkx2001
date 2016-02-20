//Cracked by Roath
inherit ROOM;

void create()
{
	set("short","第十八层地狱");
	set("long","这里是地狱的最底层...\n");
	set("valid_startroom",1);
	set("cost", 0);
	setup();
}

void init()
{
	object ob = this_player();

	if (!wizardp(ob)) {
		add_action("block_cmd","",1);
		ob->set("startroom", "/d/death/hell");
	}
}

int block_cmd()
{
	string cmd;
	cmd = query_verb();
	if (cmd == "say" || cmd == "tell" || cmd == "reply" || cmd == "who" ||
		cmd == "look" || cmd == "quit" || cmd == "suicide" || cmd == "goto")

		return 0;
	return 1;
}
