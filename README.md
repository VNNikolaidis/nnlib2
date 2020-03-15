# nnlib2
C++ Library for creating Artificial Neural Networks (ANNs) and related R package containing some ANNs implemented in this library.

To compile for a particular target the following are available in header nnlib2.h:
NNLIB2_FOR_GCC for gcc (minor mods)
NNLIB2_FOR_RCPP for R (Rcpp) package of nnlib2 NNs
NNLIB2_FOR_MFC_UI for MS-Windows (MFC and VS6) support and GUI to nnlib2
or define none of these for unspecified targer.

nnlib2 C++ Neural Network library goals:

⦁	To act as a framework for creating NNs, allowing a uniform code-writing style for NN implementations.
⦁	To be versatile and sufficient for prototyping and experimentation with new NN models.
⦁	To simplify NN implementation, with readable, intuitive code, whose syntax is clear and follows NN concepts.
⦁	To be verbose, so that the NN implementation code is readable and self-explanatory (especially to people familiar with object-oriented programming).
⦁	To be fit for prototyping or teaching NNs.
⦁	To provide an alternative OO-based base library for defining NNs, an approach that may be appealing to some of its possible users. As programming is not only about functionality but also (especially in OO approaches) about creating models of the problem at hand, This OO based library may be more acceptable to some users who would like to have classes for each of the traditional NN components, and build on those by inheriting or modifying and extending their methods as  needed,
⦁	To be fit for implementing arbitrary and experimental Neural Network topologies and functionalities.
⦁	To revive a Neural Network library whose early versions were created many years ago [PHD], were successfully used in various applications, but never publicized.
⦁	To be written in C++ code in a manner that is:
⦁	Compatible with various C++ compilers (including older compilers for legacy systems, compilers with partial or no STL support, compilers targeting systems of limited processing power, etc.).
⦁	Compatible with various C++ project types (console, GUI-based, etc).
⦁	Compatible and usable in R via Rcpp.
⦁	Compatible with Microsoft Foundation Classes (MFC, by inheriting nn_with_ui instead of nn class for NNs that provides a NN GUI in MS-Windows applications).
⦁	To allow further development, improvement and refinement of the library by making it public to programmers and data scientists. 
The library was meant to be a tool for creating “any” (at least traditional) NN model in C++; it currently includes the following Artificial Neural System (ANS) implementations:
⦁	Learning Vector Quantization (LVQ) (supervised) in class lvq_nn (parent class nn)
⦁	Self-Organizing Map (SOM) (unsupervised) Kohonen’s famous kmeans-like NN) in class som_nn (parent class lvq_nn)
⦁	Plain Back-Propagation (BP) multilayer perceptron (supervised) ) in class bp_nn
⦁	Autoencoder
⦁	Several Back-Propagation custom variations (of my own ) in class bpXX_nn
⦁	MAM
Advantages:
⦁	Framework produces compiled code, which is fast (however, see disadvantages below).
⦁	Object-Orientated model is well fit to the job of deriving new NN models from existing ones. 
⦁	Ability to serialize to/from text streams (and save/retrieve trained NNs using text files).
⦁	Closely models the components of a NN.
Disadvantages:
⦁	Not an alternative to frameworks s.a. Keras etc.
⦁	No GPU or parallel programming currently implemented (although possible). Therefore, not the most efficient way to implement NNs in terms of runtime performance (nor will ever be unless the layer and connection_set classes are parallelized). As is, this library will not implement the fastest NNs possible.


nnlib2Rcpp R Package goals:

To allow R programs interface with various ANN models implemented in nnlib2 C++ Neural Network library (via RCpp).
(nnlib2Rcpp includes nnlib2)
