LittlerootTown_IvyHouse_MapScripts::
	.byte 0


Aide1::
	lock
	faceplayer
	goto_if_set FLAG_SYS_POKEDEX_GET, Aide1_2
	msgbox Aide1_Text_1
Aide1_1:
	release
	return

Aide1_2:
	msgbox Aide1_Text_0
	goto Aide1_1


Aide2::
	lock
	faceplayer
	msgbox Aide2_Text_0
	release
	return


Aide1_Text_0:
	.string "{PLAYER}, now that you have your own\nPOKéMON, you should challenge\lPOKéMON GYMS all over the region!$"

Aide1_Text_1:
	.string "{PLAYER}, aren't you excited to pick\nyour first POKéMON?\pI wonder which one you'll choose!$"

Aide2_Text_0:
	.string "PROF. IVY's area of expertise is\nREGIONAL POKéMON FORMS.\pSome POKéMON take on different forms\nthan they do in other regions.$"
