# Project Callisto

**Unreal Engine 5.8 / C++ Gameplay Ability System Technical Showcase**

Project Callisto is an action-RPG gameplay programming technical showcase developed in Unreal Engine 5.8 using C++ and Blueprints, with a focus on Unreal Engine’s **Gameplay Ability System (GAS)**.

Rather than being a content-complete standalone game, the project is designed to demonstrate a functional GAS-driven combat framework together with the underlying ability, attribute, effect, event, AI, damage, death/respawn, cost, cooldown, and combat feedback systems.

> **Status:** ✅ Technical Showcase Complete

---

## Overview

Project Callisto focuses on building modular and reusable gameplay systems for action-RPG combat using Unreal Engine’s Gameplay Ability System.

The project separates character state, abilities, attributes, Gameplay Effects, Gameplay Events, enemy behavior, combat logic, and presentation into systems that can be extended and maintained independently.

### Core Gameplay Loop

**Spawn → Explore / Engage → Ability Activation → Combat → Damage / Hit React → Death → Respawn → Continue**

---

## Tech Stack

- **Unreal Engine 5.8**
- **C++**
- **Blueprints**
- **Gameplay Ability System (GAS)**
- Enhanced Input
- Gameplay Tags
- Gameplay Effects
- Gameplay Events
- Ability Tasks
- Unreal Engine AI
- Niagara / Gameplay Cues
- Git

---

## Technical Highlights

- Ability System Component initialization
- Gameplay Ability granting and activation
- Gameplay Tags for state and event management
- Gameplay Events and Ability Tasks
- Attribute Sets for Health / MaxHealth / Mana / MaxMana
- Attribute replication
- Gameplay Effects for attribute initialization and modification
- SetByCaller damage magnitudes
- Primary and secondary abilities
- Ability costs and cooldowns
- Enemy target searching and AI movement
- Melee and ranged enemy combat
- Projectile-based damage
- Melee tracing using Animation Notify States
- Blueprint-to-C++ gameplay system conversion
- Directional hit reactions
- Gameplay Cue-based impact and hit feedback
- Camera shake
- Area-of-effect damage
- Knockback and airborne states
- Character death and respawn
- Attribute reset
- Enemy respawn control
- Floating damage numbers
- Enemy health bars
- Health and Mana pickups
- Combat UI and gameplay feedback

---

## Development Focus

The project focuses on:

- Gameplay Ability System architecture and implementation
- Reusable C++ gameplay systems
- C++ and Blueprint integration
- Clear responsibility boundaries between Abilities, Attributes, Effects, Events, and Tags
- Event-driven combat flow
- Enemy AI and combat system integration
- Separation of gameplay logic and presentation through Gameplay Cues
- Debugging and problem solving across GAS systems
- Converting selected Blueprint systems to C++
- Additional quality-of-life features for the technical showcase

---

## Development Notes

Project Callisto was developed while following Stephen Ulibarri’s Unreal Engine 5 Gameplay Ability System course as a technical learning reference.

This project does **not** use a completed course project as its base.

I created the Unreal Engine 5.8 project from scratch and personally implemented the C++ classes, Blueprint logic, GAS systems, combat flow, debugging, testing, and project-specific modifications.

The course served as instructional guidance for the underlying concepts and structure, while the implementation, integration, troubleshooting, optional C++ conversions, quality-of-life additions, and final technical showcase were completed by me.

---

## 日本語

**Project Callisto** は、Unreal Engine 5.8、C++、Blueprintを使用して制作した、Gameplay Ability System（GAS）を中心としたアクションRPG向けゲームプレイプログラミング・テクニカルショーケースです。

完成したゲーム作品そのものではなく、GASを用いたアビリティ、Attribute、Gameplay Effect、Gameplay Event、敵AI、ダメージ処理、死亡・リスポーン、コスト・クールダウン、Combat Feedbackなどのシステムを、実際に動作する形で実装・検証することを目的としています。

### 実装したゲームプレイループ

**Spawn → Explore / Engage → Ability Activation → Combat → Damage / Hit React → Death → Respawn → Continue**

### 開発フォーカス

- Gameplay Ability Systemの理解と実装
- C++による再利用可能なゲームプレイシステム
- C++とBlueprintの連携
- Ability / Attribute / Effect / Event / Tag間の責務分離
- Event-drivenな戦闘処理
- Enemy AIとCombat Systemの統合
- Gameplay Cueを利用した演出とロジックの分離
- GASシステム全体のデバッグ・問題解決
- Blueprintで実装した一部機能のC++化
- 技術展示向けのQoL機能追加

### 制作について

本作は、Stephen Ulibarri氏のUnreal Engine 5 Gameplay Ability System講座を技術的な学習資料として使用しながら制作しました。

講座の完成済みプロジェクトを使用したものではなく、  
**Unreal Engine 5.8上でプロジェクト構成、C++クラス、Blueprintロジック、GASシステム、戦闘処理、デバッグ、テストをすべて自分で一から実装しています。**

講座内容を技術的なガイドラインとして参照しつつ、任意セクションのC++化、実装中の問題解決、Gameplay CueやCombat Systemの統合、QoL機能、プロジェクト固有の調整を追加しました。

---

## Third-Party Content

This repository is intended primarily for portfolio and educational review.

Third-party assets, plugins, Unreal Engine content, educational materials, and other external resources remain the property of their respective copyright holders and are subject to their own licenses.

Course-provided or third-party materials are not redistributed in this repository unless redistribution is explicitly permitted.

---

## License

Original source code and original project material authored specifically for Project Callisto are provided under the terms described in the [LICENSE](LICENSE) file.

Unreal Engine and related technologies are trademarks or intellectual property of Epic Games, Inc.
