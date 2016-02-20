//Cracked by Roath
int ask_menpai (string* message)
{	int count, total;
	total = sizeof(message);
	for (count = 0; count < total; count++)
	{	command(message[count]);
	}
	return 1;
}

void attempt_apprentice(object ob)
{
	command("shake");
	command("say 要拜师，你得去拜我师父。");
	return;
}

