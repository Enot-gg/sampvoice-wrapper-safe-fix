#if defined _sampvoice_safe_included
	#endinput
#endif
#define _sampvoice_safe_included

#include <sampvoice>



stock SV_BOOL:SvInit_Safe(SV_UINT:bitrate)
{
	if(bitrate == 0 || bitrate > 128) bitrate = 16; 
	SvInit(bitrate);
	return SV_TRUE;
}

stock SV_UINT:SvGetVersion_Safe(SV_UINT:playerid)
{
	if(!IsPlayerConnected(playerid)) return 0;
	return SvGetVersion(playerid);
}

stock SV_BOOL:SvHasMicro_Safe(SV_UINT:playerid)
{
	if(!IsPlayerConnected(playerid)) return SV_FALSE;
	return SvHasMicro(playerid);
}

stock SV_BOOL:SvStartRecord_Safe(SV_UINT:playerid)
{
	if(!IsPlayerConnected(playerid)) return SV_FALSE;
	return SvStartRecord(playerid);
}

stock SV_BOOL:SvStopRecord_Safe(SV_UINT:playerid)
{
	if(!IsPlayerConnected(playerid)) return SV_FALSE;
	return SvStopRecord(playerid);
}

stock SV_BOOL:SvAddKey_Safe(SV_UINT:playerid, SV_UINT:keyid)
{
	if(!IsPlayerConnected(playerid)) return SV_FALSE;
	if(keyid < 0 || keyid > 255) return SV_FALSE; 
	return SvAddKey(playerid, keyid);
}

stock SV_BOOL:SvHasKey_Safe(SV_UINT:playerid, SV_UINT:keyid)
{
	if(!IsPlayerConnected(playerid)) return SV_FALSE;
	return SvHasKey(playerid, keyid);
}

stock SV_BOOL:SvRemoveKey_Safe(SV_UINT:playerid, SV_UINT:keyid)
{
	if(!IsPlayerConnected(playerid)) return SV_FALSE;
	return SvRemoveKey(playerid, keyid);
}

stock SV_VOID:SvRemoveAllKeys_Safe(SV_UINT:playerid)
{
	if(!IsPlayerConnected(playerid)) return;
	SvRemoveAllKeys(playerid);
}

stock SV_BOOL:SvMutePlayerStatus_Safe(SV_UINT:playerid)
{
	if(!IsPlayerConnected(playerid)) return SV_FALSE;
	return SvMutePlayerStatus(playerid);
}

stock SV_VOID:SvMutePlayerEnable_Safe(SV_UINT:playerid)
{
	if(!IsPlayerConnected(playerid)) return;
	SvMutePlayerEnable(playerid);
}

stock SV_VOID:SvMutePlayerDisable_Safe(SV_UINT:playerid)
{
	if(!IsPlayerConnected(playerid)) return;
	SvMutePlayerDisable(playerid);
}

stock SV_BOOL:SvAttachListenerToStream_Safe(SV_STREAM:stream, SV_UINT:playerid)
{
	if(!IsPlayerConnected(playerid)) return SV_FALSE;
	if(stream == SV_NULL) return SV_FALSE; 
	return SvAttachListenerToStream(stream, playerid);
}

stock SV_BOOL:SvHasListenerInStream_Safe(SV_STREAM:stream, SV_UINT:playerid)
{
	if(!IsPlayerConnected(playerid)) return SV_FALSE;
	if(stream == SV_NULL) return SV_FALSE;
	return SvHasListenerInStream(stream, playerid);
}

stock SV_BOOL:SvDetachListenerFromStream_Safe(SV_STREAM:stream, SV_UINT:playerid)
{
	if(!IsPlayerConnected(playerid)) return SV_FALSE;
	if(stream == SV_NULL) return SV_FALSE;
	return SvDetachListenerFromStream(stream, playerid);
}

stock SV_VOID:SvDetachAllListenersFromStream_Safe(SV_STREAM:stream)
{
	if(stream == SV_NULL) return;
	SvDetachAllListenersFromStream(stream);
}

stock SV_BOOL:SvAttachSpeakerToStream_Safe(SV_STREAM:stream, SV_UINT:playerid)
{
	if(!IsPlayerConnected(playerid)) return SV_FALSE;
	if(stream == SV_NULL) return SV_FALSE;
	return SvAttachSpeakerToStream(stream, playerid);
}

stock SV_BOOL:SvHasSpeakerInStream_Safe(SV_STREAM:stream, SV_UINT:playerid)
{
	if(!IsPlayerConnected(playerid)) return SV_FALSE;
	if(stream == SV_NULL) return SV_FALSE;
	return SvHasSpeakerInStream(stream, playerid);
}

stock SV_BOOL:SvDetachSpeakerFromStream_Safe(SV_STREAM:stream, SV_UINT:playerid)
{
	if(!IsPlayerConnected(playerid)) return SV_FALSE;
	if(stream == SV_NULL) return SV_FALSE;
	return SvDetachSpeakerFromStream(stream, playerid);
}

stock SV_VOID:SvDetachAllSpeakersFromStream_Safe(SV_STREAM:stream)
{
	if(stream == SV_NULL) return;
	SvDetachAllSpeakersFromStream(stream);
}

stock SV_VOID:SvDeleteStream_Safe(SV_STREAM:stream)
{
	if(stream == SV_NULL) return;
	
	SvDetachAllListenersFromStream(stream);
	SvDetachAllSpeakersFromStream(stream);
	

	SvDeleteStream(stream);
}

stock SV_VOID:SvUpdateDistanceForLStream_Safe(SV_LSTREAM:lstream, SV_FLOAT:distance)
{
	if(lstream == SV_NULL) return;
	if(distance < 0.0) return; 
	SvUpdateDistanceForLStream(lstream, distance);
}

stock SV_VOID:SvUpdatePositionForLPStream_Safe(SV_LPSTREAM:lpstream, SV_FLOAT:posx, SV_FLOAT:posy, SV_FLOAT:posz)
{
	if(lpstream == SV_NULL) return;
	SvUpdatePositionForLPStream(lpstream, posx, posy, posz);
}


stock SV_VOID:SvCleanupPlayerStreams(SV_UINT:playerid)
{
	
	if(playerid < 0 || playerid >= MAX_PLAYERS) return;
	new version = SvGetVersion(playerid);
	if(version > 0)
	{
		SvStopRecord(playerid);
		SvRemoveAllKeys(playerid);
	}
	
}

stock SV_SLSTREAM:SvCreateSLStreamAtPlayer_Safe(SV_FLOAT:distance, SV_UINT:playerid, SV_UINT:color = SV_NULL, name[] = "")
{
	if(!IsPlayerConnected(playerid)) return SV_NULL;
	if(distance < 0.0) distance = 40.0; 
	return SvCreateSLStreamAtPlayer(distance, playerid, color, name);
}

stock SV_DLSTREAM:SvCreateDLStreamAtPlayer_Safe(SV_FLOAT:distance, SV_UINT:maxplayers, SV_UINT:playerid, SV_UINT:color = SV_NULL, name[] = "")
{
	if(!IsPlayerConnected(playerid)) return SV_NULL;
	if(distance < 0.0) distance = 40.0;
	if(maxplayers < 1) maxplayers = 10;
	return SvCreateDLStreamAtPlayer(distance, maxplayers, playerid, color, name);
}

