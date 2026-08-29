#include "GameplayTags/CallistoTags.h"

namespace CallistoTags
{
	namespace SetByCaller
	{
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(Projectile, "CallistoTags.SetByCaller.Projectile", "Tag for Set by Caller Magnitude for Projectiles")
	}
	
	namespace CallistoAbilities
	{
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(ActivateOnGiven, "CallistoTags.CallistoAbilities.ActivateOnGiven", "Tag for Abilities that should activate immediately once given.")
		
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(Primary, "CallistoTags.CallistoAbilities.Primary", "Tag for the Primary Ability")
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(Secondary, "CallistoTags.CallistoAbilities.Secondary", "Tag for the Secondary Ability")
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(Tertiary, "CallistoTags.CallistoAbilities.Tertiary", "Tag for the Tertiary Ability")
		
		namespace Enemy
		{
			UE_DEFINE_GAMEPLAY_TAG_COMMENT(Attack, "CallistoTags.CallistoAbilities.Enemy.Attack", "Enemy Attack Tag")
		}
	}
	
	namespace Events
	{
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(KillScored, "CallistoTags.Events.KillScored", "Tag for the KillScored Event")
		
		namespace Player
		{
			UE_DEFINE_GAMEPLAY_TAG_COMMENT(HitReact, "CallistoTags.Events.Player.HitReact", "Tag for the Player HitReact Event")
			UE_DEFINE_GAMEPLAY_TAG_COMMENT(Death, "CallistoTags.Events.Player.Death", "Tag for the Player Death Event")
		}
		
		namespace Enemy
		{
			UE_DEFINE_GAMEPLAY_TAG_COMMENT(HitReact, "CallistoTags.Events.Enemy.HitReact", "Tag for the Enemy HitReact Event")
			UE_DEFINE_GAMEPLAY_TAG_COMMENT(EndAttack, "CallistoTags.Events.Enemy.EndAttack", "Tag for the Enemy Ending an Attack")
			UE_DEFINE_GAMEPLAY_TAG_COMMENT(MeleeTraceHit, "CallistoTags.Events.Enemy.MeleeTraceHit", "Tag for the Enemy Melee Trace Hit")
		}
	}
}