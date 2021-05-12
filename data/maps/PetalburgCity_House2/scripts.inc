PetalburgCity_House2_MapScripts::
	.byte 0


MikanOldRodFisherman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_OLD_ROD, MikanOldRodFisherman_2
	msgbox MikanOldRodFisherman_Text_1, MSGBOX_AUTOCLOSE
	giveitem_std ITEM_OLD_ROD, 1, 0
	msgbox MikanOldRodFisherman_Text_2, MSGBOX_AUTOCLOSE
	setflag FLAG_RECEIVED_OLD_ROD
	release
	end

MikanOldRodFisherman_2:
	msgbox MikanOldRodFisherman_Text_0, MSGBOX_AUTOCLOSE
	release
	end


MikanShellder::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SHELLDER, 0
	msgbox MikanShellder_Text_0, MSGBOX_DEFAULT
	waitmoncry
	release
	end


MikanOldRodFisherman_Text_0:
	.string "So, how goes the fishing?$"

MikanOldRodFisherman_Text_1:
	.string "I can sense you have a knack\nat seafaring.\pHere, take this. It's one of my\nolder FISHING RODS.$"

MikanOldRodFisherman_Text_2:
	.string "Simply press the A Button if you get\na bite!$"

MikanShellder_Text_0:
	.string "SHELLDER: Krrkrr!$"
