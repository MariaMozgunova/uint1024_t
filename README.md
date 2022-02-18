<div id="top"></div>



<!-- PROJECT SHIELDS -->
<!--
*** I'm using markdown "reference style" links for readability.
*** Reference links are enclosed in brackets [ ] instead of parentheses ( ).
*** See the bottom of this document for the declaration of the reference variables
*** for contributors-url, forks-url, etc. This is an optional, concise syntax you may use.
*** https://www.markdownguide.org/basic-syntax/#reference-style-links
-->
[![MIT License][license-shield]][license-url]
[![LinkedIn][linkedin-shield]][linkedin-url]



<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#installation">Installation</a></li>
      </ul>
    </li>
    <li><a href="#usage">Usage</a></li>
    <li><a href="#license">License</a></li>
    <li><a href="#contact">Contact</a></li>
    <li><a href="#acknowledgments">Acknowledgments</a></li>
  </ol>
</details>



<!-- ABOUT THE PROJECT -->
## About The Project

This is the implementation of uint1024_t which is a custom data type for [arbitrary-precision arithmetic](https://en.wikipedia.org/wiki/Arbitrary-precision_arithmetic). uint1024_t is stored as an array of uint8_t where two decimal digits stored in each array cell.

The following functions are accessible:

- **uint1024_t from_uint(unsigned int x)** - generate uint1024_t from unsigned int
- **uint1024_t add_op(uint1024_t \*x, uint1024_t \*y)** - add two numbers x and y
-  **uint1024_t subtr_op(uint1024_t \*x, uint1024_t \*y)** - subtruct y from x
-  **uint1024_t mult_op(uint1024_t \*x, uint1024_t \*y)** - multiply x and y (implemented as the most straightforward algorithms used for multiplying numbers by hand (as taught in primary school))
-  **void printf_value(uint1024_t \*x)** - output value of x to std::cout
-  **void scanf_value(uint1024_t \*x)** - read value of x from std::cin


<p align="right">(<a href="#top">back to top</a>)</p>



<!-- GETTING STARTED -->
## Getting Started

To be able to use this uint1024_t implementation follow these simple example steps.

### Installation

1. Clone the repo `git clone https://github.com/MariaMozgunova/uint1024_t.git`
2. include uint1024_t implementation into your code `#include "uint1024_t/utils.c"`

<p align="right">(<a href="#top">back to top</a>)</p>



<!-- USAGE EXAMPLES -->
## Usage

See `uint1024_t.c` for examples of usage.

<p align="right">(<a href="#top">back to top</a>)</p>



<!-- LICENSE -->
## License

Distributed under the MIT License. See `LICENSE` for more information.

<p align="right">(<a href="#top">back to top</a>)</p>



<!-- CONTACT -->
## Contact

Maria Mozgunova - [Twitter - @MariaMozgunova](https://twitter.com/MariaMozgunova) - mariiamozgunova@gmail.com

Project Link: [https://github.com/MariaMozgunova/uint1024_t](https://github.com/MariaMozgunova/uint1024_t)

<p align="right">(<a href="#top">back to top</a>)</p>



<!-- ACKNOWLEDGMENTS -->
## Acknowledgments

* [README Template](https://github.com/othneildrew/Best-README-Template)

<p align="right">(<a href="#top">back to top</a>)</p>



<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[license-shield]: https://img.shields.io/github/license/othneildrew/Best-README-Template.svg?style=for-the-badge
[license-url]: https://github.com/MariaMozgunova/uint1024_t/blob/master/LICENSE
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555
[linkedin-url]: https://www.linkedin.com/in/mariamozgunova/
