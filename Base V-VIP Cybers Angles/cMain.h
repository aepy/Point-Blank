//-----------------------------------------------------------------------------------------------------------------------------------------------------------||
//----------------------------------------------------------|| BASE INI MILIK HELJUNAI SYAHPUTRA ||----------------------------------------------------------||
//-----------------------------------------------------------------------------------------------------------------------------------------------------------||
#ifndef _ZRCTEAM_H
#define _ZRCTEAM_H

typedef HRESULT (WINAPI* tEndScene)(LPDIRECT3DDEVICE9 pDevice);
tEndScene oEndScene = NULL;

typedef HRESULT (WINAPI* tDrawIndexedPrimitive)(LPDIRECT3DDEVICE9 pDevice, D3DPRIMITIVETYPE PrimType,INT BaseVertexIndex,UINT MinVertexIndex,UINT NumVertices,UINT startIndex,UINT primCount);
tDrawIndexedPrimitive oDrawIndexedPrimitive  = NULL;

BOOL Create;
LPDIRECT3DVERTEXBUFFER9 Stream_Data;
UINT Offset = 0;
UINT Stride = 0;
LPDIRECT3DDEVICE9 npDevice; 


char *Moptfolder          []   = {"Open", "Close"}; 
char *Moptonoff           []   = {"Off", "On"};
char *MoptDsb			  []   = {"Perbaikan"};
char *MoptTarget		  []   = {"Head", "Body", "Stomach", "Titit", "Left Waist", "Right Waist", "Left Knee", "Right Knee", "Left Foot", "Right Foot", "Left Hand", "Right Hand"};
char *Moptplant		      []   = {"Off", "Site A & B"};
char *Moptcrozz			  []   = {"Off", "Green", "Red", "Sky Blue", "Yellow", "White"};
char *MoptRank			  []   = {"Off", "GM"};
char *MoptBeret			  []   = {"Off", "Assault", "Submachinegun", "Shootgun", "Sniper", "Pistol", "Best Clan", "Red Star", "Yellow Star", "Cross Knife", "GM", "Bope", "General", "PBNC5", "Kopassus"};
char *MoptHedger		  []   = {"Off", "Tracking ++", "Tracking Red ++"};
char *MoptHOT			  []   = {"Off", "SCAR", "Famas G2","AK Sopmod","Famas G2 COM","Famas G2 SN","Famas M203"};
char *MoptItem			  []   = {"Off", "WPSmoke D","Bread Granade","Candy Granade","Lantern Granade","Decoy Bomb"};
char *MoptSec			  []   = {"Off", "HK-69"};
char *MoptRPG			  []   = {"Off", "RPG-7"};
char *MoptLC			  []   = {"OFF", "Famas L.C", "K-201", "AK 47 FC"};
char *MoptPistol		  []   = {"OFF", "Dual Handgun", "HK-69"};
char *MopSmoke			  []   = {"OFF", "WP Smoke", "WP Smoke D.", "Chocolate Grenade", "Candy Grenade", "Lantern Grenade", "Bread Grenade", "Decoy Bomb"};


#endif

