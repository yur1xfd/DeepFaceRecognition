import argparse
from deepface import DeepFace
import os
import json

def process(images_dir, output_dir):
    p = os.listdir(images_dir)
    p = [os.path.join(images_dir, x) for x in p]
    dct = {}
    for name in p:
        face_objs = DeepFace.extract_faces(img_path=name, detector_backend="yolov8", align=False)
        faces = [{k: x['facial_area'][k] for k in ['x', 'y', 'w', 'h']} for x in face_objs] 
        dct[name] = faces
    with open(os.path.join(output_dir, 'bounding_boxes.json'), 'w') as f:
        json.dump(dct, f, indent=4)


if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('-i', '--image_path', required=True)
    parser.add_argument('-o', '--output_path', required=True)
    args = parser.parse_args()
    process(args.image_path, args.output_path)
