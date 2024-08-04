// Fill out your copyright notice in the Description page of Project Settings.


#include "Item/Weapon/Weapon.h"

#include "Characters/SlashCharacter.h"


void AWeapon::OnSphereEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
                                 UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	Super::OnSphereEndOverlap(OverlappedComp, OtherActor, OtherComp, OtherBodyIndex);
}

void AWeapon::OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                              UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
                              const FHitResult& SweepResult)
{
	Super::OnSphereOverlap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);

	UE_LOG(LogTemp, Warning, TEXT("SlashCharacter is not valid1"));
	ASlashCharacter* SlashCharacter = Cast<ASlashCharacter>(OtherActor);
	
	UE_LOG(LogTemp, Warning, TEXT("SlashCharacter is not valid2"));
	if (SlashCharacter)
	{
		UE_LOG(LogTemp, Warning, TEXT("SlashCharacter is valid3"));
		FAttachmentTransformRules TransformRules(EAttachmentRule::SnapToTarget, true);
		ItemMesh->AttachToComponent(SlashCharacter->GetMesh(), TransformRules, FName("RightHandSocket"));
	}
}
