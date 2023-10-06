# Prisoner simulator

C++20

Arguments example: ```--mode=tournament
--steps=10
--matrix=matrix.txt
KindRepeaterStrategy
EvilRepeaterStrategy
KindDumbassStrategy
EvilDumbassStrategy
RandomStrategy
KindForgivingRepeaterStrategy
InconsistentStrategy```

Available modes: `fast`, `detailed`, `tournament`

To add new strategy, create it in `Player/Strategies`, inherit from `IStrategy`.
Then create its branch in `PlayerFactory::CreatePlayer()`.