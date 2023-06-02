/* Leia o arquivo README.md para entender melhor e saber mais coisas
sobre o sistema. */

#include "a_samp.inc"
#include "DOF2.inc"

#define Funcao::%0(%1) 		forward %0(%1);\
							    public %0(%1)
							
enum enum_Jogador
{
	user_id
}
new JogadorInfo[MAX_PLAYERS][enum_Jogador];

public OnPlayerText(playerid, text[])
{
	new stringid[125];
	format(stringid, 125, "{81DAF5}[%d] diz: {FFFFFF}%s", JogadorInfo[playerid][user_id], text);
	ProxDetector(20.0, playerid, stringid, 0xE6E6E6E6, 0xE6E6E6E6, 0xE6E6E6E6, 0xE6E6E6E6, 0xE6E6E6E6);
	return 0;
}
public OnGameModeInit()
{
	ShowNameTags(0);
	return 1;
}
stock Criar_userid(playerid)
{
	JogadorInfo[playerid][user_id] = Criarid();
	return 1;
}
stock Criarid()
{
	new str[50];
	format(str, 50, "Quantidade_Userid.cfg");
	if(!DOF2_FileExists(str)) DOF2_CreateFile(str);
	new id = DOF2_GetInt(str, "Quantidade") + 1;
	DOF2_SetInt(str, "Quantidade", id);
	return id;
}
Funcao::SetPlayerId(playerid)
{
	new stringid[7];
	format(stringid, 5, "%d", JogadorInfo[playerid][user_id]);
	SetPlayerChatBubble(playerid, stringid, -1, 16.0, 7000);
	return 1;
}
CMD:pagar(playerid, params[]) //Pegue como exemplo para comandos.
{
    new ID, money;
    if(sscanf(params, "im", ID, money)) return SendClientMessage(playerid, -1, "Erro: Use /pagar [ ID ] [ Valor ]");
	for(new i = 0; i < MAX_PLAYERS; i++)
	{
		if(JogadorInfo[i][user_id] == ID)
		{
		    //COD
		}
	}
	SendClientMessage(playerid, 0xB4B5B7FF, "ID Invalido.");
	return 1;
}
Funcao::ProxDetector(Float:radi, playerid, string[],col1,col2,col3,col4,col5)
{
    if(IsPlayerConnected(playerid))
    {
        new Float:posx, Float:posy, Float:posz;
        new Float:oldposx, Float:oldposy, Float:oldposz;
        new Float:tempposx, Float:tempposy, Float:tempposz;
        GetPlayerPos(playerid, oldposx, oldposy, oldposz);
        foreach(new i: Player)
        {
            if(IsPlayerConnected(i))
            {
                if(!BigEar[i])
                {
                    GetPlayerPos(i, posx, posy, posz);
                    tempposx = (oldposx -posx);
                    tempposy = (oldposy -posy);
                    tempposz = (oldposz -posz);
                    if (((tempposx < radi/16) && (tempposx > -radi/16)) && ((tempposy < radi/16) && (tempposy > -radi/16)) && ((tempposz < radi/16) && (tempposz > -radi/16)))
                    {
                        SCM(i, col1, string);
                    }
                    else if (((tempposx < radi/8) && (tempposx > -radi/8)) && ((tempposy < radi/8) && (tempposy > -radi/8)) && ((tempposz < radi/8) && (tempposz > -radi/8)))
                    {
                        SCM(i, col2, string);
                    }
                    else if (((tempposx < radi/4) && (tempposx > -radi/4)) && ((tempposy < radi/4) && (tempposy > -radi/4)) && ((tempposz < radi/4) && (tempposz > -radi/4)))
                    {
                        SCM(i, col3, string);
                    }
                    else if (((tempposx < radi/2) && (tempposx > -radi/2)) && ((tempposy < radi/2) && (tempposy > -radi/2)) && ((tempposz < radi/2) && (tempposz > -radi/2)))
                    {
                        SCM(i, col4, string);
                    }
                    else if (((tempposx < radi) && (tempposx > -radi)) && ((tempposy < radi) && (tempposy > -radi)) && ((tempposz < radi) && (tempposz > -radi)))
                    {
                        SCM(i, col5, string);
                    }
                }
                else
                {
                    SCM(i, col1, string);
                }
            }
        }
    }
    return 1;
}