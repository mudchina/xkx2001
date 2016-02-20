//Cracked by Kafei
// aliasd.c

string current_alias;

mapping global_alias = ([
	"l":	"look",
	"n":	"go north",
	"e":	"go east",
	"w":	"go west",
	"s":	"go south",
	"nu":	"go northup",
	"eu":	"go eastup",
	"wu":	"go westup",
	"su":	"go southup",
	"nd":	"go northdown",
	"ed":	"go eastdown",
	"wd":	"go westdown",
	"sd":	"go southdown",
	"ne":	"go northeast",
	"se":	"go southeast",
	"nw":	"go northwest",
	"sw":	"go southwest",
	"u":	"go up",
	"d":	"go down",
	"i":	"inventory",
	"tf":	"team fight",
	"tt":	"team talk",
	"tt*":	"team talk*" // for emote support Zhuang@XKX
]);

string get_current_alias()
{
	if(this_player(1))
		return this_player(1)->query("id") + ": " + current_alias + " in " + (environment(this_player(1))? file_name(environment(this_player(1))) : "");
	else 	return current_alias;
}

string process_global_alias(string arg)
{
	string *word;

	current_alias = arg;

	if (arg[0]=='\'') return "say " + arg[1..strlen(arg)-1];

	word = explode(arg, " ");
	if( sizeof(word) && !undefinedp(global_alias[word[0]]) ) {
		word[0] = global_alias[word[0]];
		return implode(word, " ");
	}

	return arg;
}
