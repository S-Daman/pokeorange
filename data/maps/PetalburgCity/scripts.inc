PetalburgCity_MapScripts::
	.byte 0


MikanSenta::
	lock
	faceplayer
	goto_if_set FLAG_BADGE01_GET, MikanSenta_2
	msgbox MikanSenta_Text_1, MSGBOX_AUTOCLOSE
	release
	return

MikanSenta_2:
	msgbox MikanSenta_Text_0, MSGBOX_AUTOCLOSE
	release
	end


MikanGirl::
	lock
	faceplayer
	msgbox MikanGirl_Text_0, MSGBOX_AUTOCLOSE
	release
	return


MikanBoy::
	lock
	faceplayer
	msgbox MikanBoy_Text_0, MSGBOX_AUTOCLOSE
	release
	return


MikanSkipSchoolGirl::
	lock
	faceplayer
	msgbox MikanSkipSchoolGirl_Text_0, MSGBOX_AUTOCLOSE
	release
	return


MikanSign::
	lock
	msgbox MikanSign_Text_0, MSGBOX_SIGN
	release
	return


MikanGymSign::
	lock
	msgbox MikanGymSign_Text_0, MSGBOX_SIGN
	release
	return


MikanSchool::
	lock
	msgbox MikanSchool_Text_0, MSGBOX_SIGN
	release
	return


MikanSenta_Text_0:
	.string "Hmph! I acknowledge your skill…\pRematch my sister anytime you want to!$"

MikanSenta_Text_1:
	.string "My sister, CISSY, is the strongest\nTRAINER I know!\pFat chance you can beat her!$"

MikanGirl_Text_0:
	.string "There is word that HORSEA were spotted\nin the pond behind the GYM.$"

MikanBoy_Text_0:
	.string "Hey, you're a fresh POKéMON TRAINER?\pThere's a GYM here.\nYou should go check it out!$"

MikanSkipSchoolGirl_Text_0:
	.string "Want to know a little secret?\pI skipped school today! Hehehe…$"

MikanSign_Text_0:
	.string "MIKAN ISLAND\nA Delicate First Step Forward$"

MikanGymSign_Text_0:
	.string "MIKAN ISLAND POKéMON GYM\nLEADER: CISSY\lThe ORANGE CREW's Water Beauty!$"

MikanSchool_Text_0:
	.string "MIKAN ISLAND POKéMON SCHOOL$"
