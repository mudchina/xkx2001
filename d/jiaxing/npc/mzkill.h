//Cracked by Roath
//Jay 8/12/96

void init()
{
        object ob;
        ::init();
        if (interactive(ob = this_player()) && 
		(!present("mianzhao",ob) || 
		!present("mianzhao",ob)->query("equipped"))) {
		remove_call_out("kill_ob");
                call_out("kill_ob", 1, ob);
        }
}                                                 

