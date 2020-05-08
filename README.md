# nnlib2
A collection of C++ classes and templates for creating Artificial Neural Networks.

To compile for a particular target the following are available in header nnlib2.h:

NNLIB2_FOR_GCC for gcc (minor mods)

NNLIB2_FOR_RCPP for R (Rcpp) package of nnlib2 NNs

NNLIB2_FOR_MFC_UI for MS-Windows (MFC support and GUI to nnlib2 (optional-not in this repo))

or define none of these for unspecified targer.

---

nnlib2 C++ Neural Network library goals:

⦁	To help creating Artificial Neural Network Systems (ANNs/ANS/NNs) in C++, allowing a uniform code-writing style for different NN implementations.

⦁	To be versatile and sufficient for prototyping and experimentation with new NN models, including complex multi-layer ones.

⦁ To simplify NN implementation, with classes that follow classic NN concepts.

⦁	To be fit for implementing arbitrary, dissimilar Neural Network topologies and functionalities.

⦁	To contain essential NN functionality as predefined.

⦁	To revive and improve a Neural Network library whose early versions were created many years ago [1][2].

⦁	To be written in C++ code in a manner that is: (a) Compatible with various C++ compilers (including older compilers for legacy systems, compilers with partial or no STL support, compilers targeting systems of limited processing power, etc.), (b) Compatible with various C++ project types (console, GUI-based, etc), (c) Compatible and usable in R via Rcpp. (d) Compatible with Microsoft Foundation Classes (MFC, by inheriting nn_with_ui instead of nn class for NNs that provides a NN GUI in MS-Windows applications - not included in this repo).

The library was meant to be a tool for creating “any” (at least traditional) NN model in C++; it currently includes the following Artificial Neural System (ANS) implementations:

⦁	Learning Vector Quantization (LVQ) (supervised) in class lvq_nn (parent class nn).

⦁	Self-Organizing Map (SOM) (unsupervised) (A simplified 1-D variation of Kohonen’s famous NN family) in class som_nn (parent class lvq_nn).

⦁	Back-Propagation (BP) multilayer perceptron (supervised) ("Vanilla" version) in class bp_nn.

⦁	Autoencoder (parent class bp_nn), for dimensionality reduction (a bit like PCA) or expansion.

⦁	Several Back-Propagation custom variations (of my own) in class bpXX_nn.

⦁	A simple Matrix-Associative-Memory (MAM) (<-- Note: this is the code to check first. Simplest and most recently written) 

---
Advantages:

⦁	Produces compiled code, which is fast (however, see disadvantages below).

⦁	Object-Orientated model is well fit to the job of deriving new NN models from existing ones. 

⦁	Ability to serialize to/from text streams (and save/retrieve trained NNs using text files).

⦁	Closely models the components of a NN.

Disadvantages:

⦁	Not an alternative to frameworks s.a. Keras etc.

⦁	No GPU or parallel programming currently implemented (although possible). Therefore, not the most efficient way to implement NNs in terms of runtime performance (nor will ever be unless the layer and connection_set classes are parallelized). As is, this library will not implement the fastest deep-learning NNs possible.

See also the nnlib2Rcpp R Package repo which allows R programs interface with various ANN models implemented in nnlib2 C++ Neural Network library (via RCpp).

----
We welcome anyone who wants to contribute to this project.

----
References:

[1] Nikolaidis VN, Makris IA, Stavroyiannis S (2013). “ANS-based Preprocessing of Company Performance Indicators.” Global Business and Economics Review, 15(1), 49–58.

[2] Nikolaidis V (1999). Non-Destructive Inspection (NDI) Techniques for Composite Materials using Unconventional Pattern Regognition Methods (in Greek). Ph.D. thesis, University of Patras. URL https://thesis.ekt.gr/thesisBookReader/id/11158.
