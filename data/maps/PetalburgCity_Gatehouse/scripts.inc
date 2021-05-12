PetalburgCity_Gatehouse_MapScripts::
	.byte 0


MikanGatePoliceman::
	lock
	faceplayer
	msgbox MikanGatePoliceman_Text_0, MSGBOX_AUTOCLOSE
	release
	return


MikanGatePoliceman_Text_0:
	.string "I heard a rumour that PIKACHU appear\nin TANGELO WOODS.\pFor some reason, they have the\ncry of HOOTHOOT, though.$"
