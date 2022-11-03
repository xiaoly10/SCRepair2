SCRepair2
===

SCRepair2 is different from the previous one. Instead of implementing intelligent computing through deap library, it adopts a new framework and intelligent computing algorithm set to repair smart contracts.Although the deap library is not used for calculation, its content is still retained. Users can modify it in the code and choose to use the deap library or the latest algorithm framework and algorithm set.

Here we recommend the algorithm set, which has excellent scalability and compatibility and is convenient for adding and modifying algorithms.

Current implementation supports Slither and Oyente as vulnerability detector.
Ethereum smart contract written in Solidity is supported.

Installation
===

To install SCRepair, use the following command, the dependencies will be automatically installed and configured:

```Bash
python3 setup.py install
```

To Use
===

Use the following command

```Bash
python3 CLI.py repair PATH_TO_CONTRACT
```

You also need to configure the detectors intended to be used via the `--detector` flag.
Besides, you may use `--targeted_vul` to only target subset of detected vulnerabilities.

As output, the paths to the plausible patches will be printed to the standard out.


Improvement
===

This paper improves the original intelligent computing framework and intelligent computing algorithms, and provides about 59 kinds of conventional intelligent computing. Each algorithm has passed the feasibility test, but has not been completely run, because the previous operation was not feasible.


Important Clause
===

Only more than ten smart contracts used in the original can be completed, so all the contracts used in this project, except for the 17 original contracts, are independently written and tested.

# SCRepair2
