#include "GameplayTags/CallistoTags.h"

namespace CallistoTags
{
	namespace CallistoAbilities
	{
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(ActivateOnGiven, "CallistoTags.CallistoAbilities.ActivateOnGiven", "Tag for Abilities that should activate immediately once given.")
		
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(Primary, "CallistoTags.CallistoAbilities.Primary", "Tag for the Primary Ability")
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(Secondary, "CallistoTags.CallistoAbilities.Secondary", "Tag for the Secondary Ability")
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(Tertiary, "CallistoTags.CallistoAbilities.Tertiary", "Tag for the Tertiary Ability")
	}
	
	namespace Events
	{
		namespace Enemy
		{
			UE_DEFINE_GAMEPLAY_TAG_COMMENT(HitReact, "CallistoTags.Events.Enemy.HitReact", "Tag for the Enemy HitReact Event")
		}
	}
}