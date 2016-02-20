//Cracked by Kafei
mapping mkmapping(mixed indarr, mixed valarr)
{
	mapping retval = ([]);
	string index;
	if (sizeof(indarr) != sizeof(valarr))
	{
		write("size of arrays mismatch!\n");
		return ([]);
	}
	
	for (int i = 0; i < sizeof(indarr); i++)
	{
		if (undefinedp(retval[indarr[i]]))
		{
			retval[indarr[i]] = valarr[i];
		}
		else
		{
			//write("index defined already, ignored\n");
		}
	}
	return retval;
}

mapping mk2dmapping(mixed indarr1, mixed indarr2, mixed valarr)
{
	mapping retval = ([]);
	mapping map1 = ([]);
	string index;
	
	
	if (sizeof(indarr2) != sizeof(valarr))
	{
		write("size of arrays mismatch!\n");
		return ([]);
	}

	for (int i = 0; i < sizeof(indarr1); i++)
	{
		for (int j = 0; j < sizeof(indarr2); j++)
		{ 
			map1[indarr2[j]] = valarr[j][i];
			//write(indarr1[i] + indarr2[j] + valarr[j][i] + "\n");
		}
		//write(indarr1[i] + map1[indarr2[0]] + "\n");
		if (undefinedp(retval[indarr1[i]]))
		{
			retval[indarr1[i]] = ([]) + map1;
		}
		//write(indarr1[i] + map1[indarr2[0]] + "\n");
	}
	
	return retval;
}