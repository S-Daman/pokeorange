RustboroCity_House3_MapScripts:: @ 8216190
	.byte 0

RustboroCity_House3_EventScript_OldMan:: @ 8216191
	msgbox RustboroCity_House3_Text_IGivePerfectlySuitedNicknames, MSGBOX_NPC
	end

RustboroCity_House3_EventScript_OldWoman:: @ 821619A
	msgbox RustboroCity_House3_Text_NamingPikachuPekachu, MSGBOX_NPC
	end

@ Misspelling on purpose, see nickname
RustboroCity_House3_EventScript_Pekachu:: @ 82161A3
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIKACHU, 0
	msgbox RustboroCity_House3_Text_Pekachu, MSGBOX_DEFAULT
	waitmoncry
	release
	end

RustboroCity_House3_Text_IGivePerfectlySuitedNicknames: @ 82161B6
	.string "For my own POKéMON, I give them\n"
	.string "perfectly suited nicknames!\p"
	.string "It's my expression of, uh…\n"
	.string "originality, yes, that's it!$"

RustboroCity_House3_Text_NamingPikachuPekachu: @ 821622A
	.string "But giving the name PEKACHU to\n"
	.string "a PIKACHU? It seems pointless.\p"
	.string "I suppose it is good to use a name\n"
	.string "that's easy to understand, but…$"

RustboroCity_House3_Text_Pekachu: @ 82162AB
	.string "PIKACHU: Pika!$"


RustboroCity_House3_EventScript_Pidgey:: @ 82161A3
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIDGEY, 0
	msgbox RustboroCity_House3_Text_Pidgey, MSGBOX_DEFAULT
	waitmoncry
	release
	end

RustboroCity_House3_Text_Pidgey: @ 82162AB
	.string "PIDGEY: Winnhaa!$"

RustboroCity_BirdTypeMonsCool:: @ 8216191
	lock
	faceplayer
	goto_if_set FLAG_ITEM_SHOAL_CAVE_ICE_ROOM_NEVER_MELT_ICE, RustboroCity_BirdTypeMonsCool2 
	msgbox RustboroCity_House3_Text_BirdTypeMonsCool1, MSGBOX_DEFAULT
	giveitem_std ITEM_SHARP_BEAK, 1, 0
	setflag FLAG_ITEM_SHOAL_CAVE_ICE_ROOM_NEVER_MELT_ICE
	releaseall
	end
	
RustboroCity_BirdTypeMonsCool2:: @ 8216191
	lock
	faceplayer
	msgbox RustboroCity_House3_Text_BirdTypeMonsCool2, MSGBOX_DEFAULT
	releaseall
	end
	
RustboroCity_House3_Text_BirdTypeMonsCool1: @ 82161B6
	.string "Bird POKéMON are simply the best.\p"
	.string "Here's something to make them\n"
	.string "even stronger!$"
	
RustboroCity_House3_Text_BirdTypeMonsCool2: @ 82161B6
	.string "That SHARK BEAK will increase damage\n"
	.string "from FLYING TYPE attacks!$"