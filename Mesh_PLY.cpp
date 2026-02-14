
#include "Mesh.h"

void Mesh::loadPLY(std::string path) {
	vertices.clear();
	std::ifstream file(path, std::ios::binary);

	if (!file.is_open()) {
		std::cout << "Could not load: " << path << "\n";
		return;
	}

	int numVerts = 0;
	std::string line;
	while (std::getline(file, line)) {
		std::istringstream lineStream(line);
		std::string token;
		lineStream >> token;

		if (token == "format") {
			std::string format;
			lineStream >> format;
			if (format != "binary_little_endian") {
				std::cout << "Invalid File Format\n";
				file.close();
				assert(false);
				return;
			}
		}

		if (token == "element") {
			std::string elementType;
			lineStream >> elementType;
			if (elementType == "vertex") {
				lineStream >> numVerts;
			}
		}

		if (token == "end_header") {
			break;
		}
	}

	vertices.resize(numVerts);
	for (Vertex& vertex : vertices) {
		file.read((char*)(&vertex.x), sizeof(float));
		file.read((char*)(&vertex.y), sizeof(float));
		file.read((char*)(&vertex.z), sizeof(float));

		unsigned char r, g, b, a;
		file.read((char*)(&r), sizeof(unsigned char));
		file.read((char*)(&g), sizeof(unsigned char));
		file.read((char*)(&b), sizeof(unsigned char));
		file.read((char*)(&a), sizeof(unsigned char));

		vertex.r = (float)r / 255.0f;
		vertex.g = (float)g / 255.0f;
		vertex.b = (float)b / 255.0f;
		vertex.a = (float)a / 255.0f;
	}

	file.close();
}

