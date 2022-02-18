<div id="top"></div>



<!-- PROJECT SHIELDS -->
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

This project is the implementation of uint1024_t, which is a custom data type for [arbitrary-precision arithmetic](https://en.wikipedia.org/wiki/Arbitrary-precision_arithmetic). The current implementation stores uint1024_t as an array of uint8_t. It puts two decimal digits in each array cell.

The following functions are accessible:

- **uint1024_t from_uint(unsigned int x)** - generate uint1024_t from unsigned int
- **uint1024_t add_op(uint1024_t \*x, uint1024_t \*y)** - add two numbers x and y
-  **uint1024_t subtr_op(uint1024_t \*x, uint1024_t \*y)** - subtruct y from x
-  **uint1024_t mult_op(uint1024_t \*x, uint1024_t \*y)** - multiply x and y (implemented as the most straightforward algorithms used for multiplying numbers by hand (as taught in primary school))
-  **void printf_value(uint1024_t \*x)** - output value of x to standard output
-  **void scanf_value(uint1024_t \*x)** - read value of x from standard input


<p align="right">(<a href="#top">back to top</a>)</p>



<!-- GETTING STARTED -->
## Getting Started

To use this uint1024_t implementation, follow the simple steps below.

### Installation

1. Clone the repo `git clone https://github.com/MariaMozgunova/uint1024_t.git`
2. Include uint1024_t implementation into your code `#include "uint1024_t/utils.c"`

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
