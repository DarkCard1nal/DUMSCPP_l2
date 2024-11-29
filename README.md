# DUMSCPP_l2

_Created for the course "Development using modern C++ standards" V. N. Karazin Kharkiv National University_

"SerializerMap" CMake linux program using C++17 standard.

---

## Overview

This project, **SerializerMap**, is a C++17 CMake-based application for Linux. Its primary goal is to serialize data stored in `std::map` into strings and save them in files in one or more of the following formats: **XML**, **JSON**, and **YAML**. Each format is saved into a separate file with its respective extension.

## Key Features

1. **Data structure**: 
   - The key of the `std::map` must be a `std::string`.
   - The value can be one of three types:
     1. Another `std::map`.
     2. A `std::vector`.
     3. A `std::string`.

2. **Serialization formats**:
   - **XML**:
     - Data elements are wrapped in appropriate `<tagName>` tags.
     - Uses the `EscapeXML` function to properly escape special characters (e.g., `&`, `<`, `>`, etc.).
     - For `std::map`, each key becomes a tag, and the value becomes the content.
   - **JSON**:
     - For `std::map`, data is represented as an object (`{}`), where each key is a string, and the value is also a string.
     - For `std::vector`, data is represented as an array (`[]`) containing strings.
   - **YAML**:
     - For `std::map`, keys become headers, and values are their content.
     - For `std::vector`, each element is listed with an indentation and a dash (`-`).
     - YAML has a simpler syntax as it does not require enclosing keys in quotes.

3. **Example outputs**:

### XML Representation

```xml
<data>  
  <key_to_map>  
    <key1>value1</key1>  
    <key2>value2</key2>  
  </key_to_map>  

  <key_to_string>this is a string</key_to_string>  

  <key_to_vector>  
    <item>string from vector 1</item>  
    <item>string from vector 2</item>  
  </key_to_vector>  
</data>  
```

### JSON Representation

```json
{  
  "data": {  
    "key_to_map": {  
      "key1": "value1",  
      "key2": "value2"  
    },  
    "key_to_string": "this is a string",  
    "key_to_vector": [  
      "string from vector 1",  
      "string from vector 2"  
    ]  
  }  
}  
```

### YAML Representation

```yaml
data:  
  key_to_map:  
    key1: value1  
    key2: value2  

  key_to_string: this is a string  

  key_to_vector:  
    - string from vector 1  
    - string from vector 2  
```

## Project Structure

- **Header File**: `serializer.h`
  - Contains the declarations for the serialization functions for each supported format.
  - Includes template functions for generic serialization of `std::map`, `std::vector`, and `std::string`.

- **Implementation File**: `serializer.cpp`
  - Implements three functions for each data type and format (XML, JSON, YAML).

- **Main File**: `main.cpp`
  - Demonstrates how to use the library for serialization.
  - Saves the results in files with the extensions `.xml`, `.json`, and `.yaml`.

## Usage Instructions

1. Clone the repository and navigate to the project directory.
2. Build the project using CMake:
   ```
   mkdir build && cd build
   cmake ..
   make
   ```
3. Run the executable:
   ```
   ./SerializerMap
   ```
4. The program will generate three files: `example.xml`, `example.json`, and `example.yaml`, containing the serialized data.

## Implementation Details

### XML
- Wraps each data element in `<tagName>` tags.
- Escapes special characters using the `EscapeXML` helper function.

### JSON
- Encodes `std::map` as an object (`{}`).
- Represents `std::vector` as an array (`[]`).

### YAML
- Formats `std::map` as key-value pairs with indentation.
- Formats `std::vector` as a list with a leading `-`.

## Requirements

- Linux operating system.
- C++17-compatible compiler.
- CMake 3.15 or later.

This project demonstrates how to serialize hierarchical data structures into commonly used formats, making it suitable for educational purposes or integration into larger systems requiring data persistence.
