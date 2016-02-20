//Cracked by Roath

inherit NPC;
string* menpai = ({
	"道童说道：\n",
	"         \n",
	"         \n",
	"         \n",
	"         \n",
});
int ask_menpai(string* message);

	set("inquiry", ([
			"武当"   :  (: ask_menpai, menpai:),
		]));

void greeting(object me)
{	
	say("道童笑着说道：这位" + 
			RANK_D->query_respect(me) + "\n");
	say("道童说道：你有什麽问题问我就好啦。(ask dao about 武当) \n");
	say("         或(help wudang)。\n");
 }

#include "/d/xiakedao/npc/xkdnpc.h"