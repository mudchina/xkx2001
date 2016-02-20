// Change by Server
// to.c

// inherit F_CLEAN_UP;
// Don't want this command be cleaned up while typing long string.

object gme;
string garg;

int main(object me, string arg)
{
	gme = me; garg = arg;
	me->edit( (: call_other, this_object(), ({ "do_to", gme, garg }) :) );
	return 1;
}

void do_to(object me, string arg, string str)
{
	seteuid(getuid());
	if(arg) me->force_me(arg + " " + str);
	else me->force_me(str);
}

int help(object me)
{
write(@HELP
指令格式 : to <指令>

可以一次输出多行以上的文字, <指令>通常是输出讯息的指令如
say , tell , describe , chat , reple ........等。
HELP
    );
    return 1;
}

