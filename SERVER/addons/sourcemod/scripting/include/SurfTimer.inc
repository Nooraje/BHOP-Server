#if defined _surftimer_included
 #endinput
#endif
#define _surftimer_included

/* Natives */

/**
 * Checks clients timer status
 *
 * @param client    Client's id
 * @return          True / False
 */
native bool:surftimer_GetTimerStatus(client);

/**
 * Stops client's timer.
 *
 * @param client    Client's id
 * @return          No return
 */
native surftimer_StopTimer(client);

/**
 * Starts client's timer
 *
 * @param client    Client's id
 * @return          No return
 */
native surftimer_EmulateStartButtonPress(client);

/**
 * Finishes a client's run.
 *
 * @param client    Client's id
 * @return          No return
 */
native surftimer_EmulateStopButtonPress(client);

/**
 * Get client's current runtime.
 *
 * @param client     Client's id
 * @return           Client's curren runtime as a float.
 */
native Float:surftimer_GetCurrentTime(client);

/**
 * Checks if the client has VIP status
 *
 * @param client     Clients id
 * @return           True / False
 */
native bool:surftimer_IsClientVip(client);

/**
 * Gets the rank of a client
 *
 * @param client     Client's id
 * @return           Rank as an int / -1 on failure
 */
native surftimer_GetPlayerRank(client);

/**
 * Gets the clients points
 *
 * @param client     Client's id
 * @return           points as an int / -1 on failure
 */
native surftimer_GetPlayerPoints(client);

/**
 * Safely teleports the client. Does not trigger end touches
 * and sets client location correctly.
 *
 * @param client    		Client's id
 * @param fDestination 		Teleport location
 * @param fAngle 			Teleport angle
 * @param fVelocity 		Teleport velocity
 * @param bStopTimer 		Stop the client's timer, default false
 * @return           true on success / false on failure
 */
native bool:surftimer_SafeTeleport(client, Float:fDestination[3], Float:fAngle[3], Float:fVelocity[3], bool:bStopTimer = false);

/*
		FORWARDS
						*/

/**
 * Called when a player finishes a map
 *
 * @param client     Player index.
 * @return           Plugin_Handled; to stop the player from searching.
 */
forward Action:surftimer_OnMapFinished(client, Float:fRunTime, String:sRunTime[54], rank, total);

/**
 * Called when a player recieves a checkpoint either via a stage or checkpoint zone
 *
 * @param client     Player index.
 * @return           Plugin_Handled; to stop the player from searching.
 */
forward Action:surftimer_OnCheckpoint(client, Float:fRunTime, String:sRunTime[54], Float:fPbCp, String:sPbDiff[16], Float:fSrCp, String:sSrDiff[16]);


/**
 * Called when a player finishes a bonus
 *
 * @param client     Player index.
 * @return           Plugin_Handled; to stop the player from searching.
 */
forward Action:surftimer_OnBonusFinished(client, Float:fRunTime, String:sRunTime[54], rank, total, bonusid);

/**
 * Called when a player finishes a map in practice mode
 *
 * @param client     Player index.
 * @return           Plugin_Handled; to stop the player from searching.
 */
 forward Action:surftimer_OnPracticeFinished(client, Float:fRunTime, String:sRunTime[54]);


public SharedPlugin:__pl_surftimer =
{
	name = "surftimer",
	file = "surftimer.smx",
	#if defined REQUIRE_PLUGIN
	required = 1,
	#else
	required = 0,
	#endif
};

public __pl_surftimer_SetNTVOptional()
{
	MarkNativeAsOptional("surftimer_GetTimerStatus");
	MarkNativeAsOptional("surftimer_StopTimer");
	MarkNativeAsOptional("surftimer_EmulateStartButtonPress");
	MarkNativeAsOptional("surftimer_EmulateStopButtonPress");
	MarkNativeAsOptional("surftimer_GetCurrentTime");
	MarkNativeAsOptional("surftimer_ClientIsVIP");
	MarkNativeAsOptional("surftimer_GetServerRank");
	MarkNativeAsOptional("surftimer_SafeTeleport");
}
