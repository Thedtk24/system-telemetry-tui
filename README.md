# Real-Time System Telemetry Pipeline

Système de télémétrie en temps réel en C++17 simulant un environnement embarqué. Le projet repose sur une architecture modulaire avec un processus producteur de métriques, un consommateur affichant un tableau de bord dynamique (TUI), et une communication inter-processus via un pipe Unix.

## Fonctionnalités
- **Producteur (`producer`) :** Génération continue de métriques système (CPU, RAM, température, statuts) sérialisées au format CSV.
- **Consommateur (`consumer`) :** Affichage d'un tableau de bord interactif dans le terminal.
- **TUI & Historique :** Barres de progression, suivi des pics maximaux, mini-graphe d'historique ASCII (*sparkline*) et alertes en couleur ANSI.

---

## Compilation

À la racine du projet :

```bash
mkdir build && cd build
cmake ..
make
```

## Utilisation 

Lancez le pipeline en connectant le producteur au consommateur via un pipe :

```bash
./producer/producer | ./consumer/consumer
```

### Aperçu du rendu